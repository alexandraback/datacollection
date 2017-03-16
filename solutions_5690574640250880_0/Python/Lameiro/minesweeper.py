def format_grid(grid, width, height):
    found, x, y = search_for('.', grid, width, height, False)
    if not found:
        # no dot found, single b is expected
        found_b, x, y = search_for('b', grid, width, height, False)
        found_b, count = search_for('b', grid, width, height, True)

        if not found_b:
            assert False, "bug not found b"

        if count != 1:
            assert False, "bug count!=1"

        if x == y == -1:
            assert False, "bug xy"

    grid[y][x] = 'c'

    l = []
    for line in grid:
        l.append(''.join(line).replace('b', '.'))

    return '\n'.join(l)


def deepcopy(list_of_lists):
    return [l[:] for l in list_of_lists]


def read_list_of(numtype):
    return map(numtype, raw_input().split())


def tuplify(grid, *args, **kwargs):
    l = []
    for x in grid:
        l.append(tuple(x))

    return tuple(l)


def create_empty_grid(width, height):
    grid = []
    for i in xrange(height):
        grid.append(['.'] * width)

    return grid


def check_at_least_one_neighbor(option_x, option_y, grid, width, height, neighbor_char):
    for neighbor_x in xrange(option_x - 1, option_x + 2):
        if neighbor_x < 0 or neighbor_x >= width: continue

        for neighbor_y in xrange(option_y - 1, option_y + 2):
            if neighbor_x == option_x and neighbor_y == option_y: continue
            if neighbor_y < 0 or neighbor_y >= height: continue

            if grid[neighbor_y][neighbor_x] == neighbor_char:
                return True
    return False


def mark_seen(option_x, option_y, grid, width, height):
    grid[option_y][option_x] = 'S'
    for neighbor_x in xrange(option_x - 1, option_x + 2):
        if neighbor_x < 0 or neighbor_x >= width: continue

        for neighbor_y in xrange(option_y - 1, option_y + 2):
            if neighbor_x == option_x and neighbor_y == option_y: continue
            if neighbor_y < 0 or neighbor_y >= height: continue

            if grid[neighbor_y][neighbor_x] == '.':
                mark_seen(neighbor_x, neighbor_y, grid, width, height)


def search_for(char, grid, width, height, count):
    the_count = 0
    for option_x in xrange(width):
        for option_y in xrange(height):
            if grid[option_y][option_x] == char:
                if count:
                    the_count += 1
                else:
                    return True, option_x, option_y

    if count:
        return the_count > 0, the_count
    else:
        return False, -1, -1


def cache(pre, store):
    def closure(fun):
        def decorated(*args, **kwargs):
            ck = pre(*args, **kwargs)
            if ck in store:
                return store[ck]
            r = fun(*args, **kwargs)
            store[ck] = r
            return r

        return decorated
    return closure

cache_store = {}
@cache(tuplify, cache_store)
def grid_ok(grid, width, height):
    # grid is OK if all . are connected in the same group and or there is only one b
    found_dot, option_x, option_y = search_for('.', grid, width, height, False)

    if not found_dot:
        # no remaining dot, last hope is to have only one b
        found_b, count = search_for('b', grid, width, height, True)
        return count == 1

    # all Bs must be neighbors of a dot
    # for all b:
    for i in xrange(width):
        for j in xrange(height):
            if grid[j][i] == 'b':
                has_dot_neighbor = check_at_least_one_neighbor(i, j, grid, width, height, '.')
                if not has_dot_neighbor:
                    return False


    copy_grid = deepcopy(grid)
    mark_seen(option_x, option_y, copy_grid, width, height)

    still_find_dots, i, j = search_for('.', copy_grid, width, height, False)

    result = not still_find_dots
    return result
#
#
# def add_mine_slow(option_x, option_y, grid, width, height):
#     if option_x >= 1 and option_x < width-1 and option_y >= 1 and option_y < height -1:

#@profile
def add_mine(option_x, option_y, grid, width, height):
    grid[option_y][option_x] = '*'

    for neighbor_x in xrange(option_x - 1, option_x + 2):
        if neighbor_x < 0 or neighbor_x >= width: continue

        for neighbor_y in xrange(option_y - 1, option_y + 2):
            if neighbor_x == option_x and neighbor_y == option_y: continue
            if neighbor_y < 0 or neighbor_y >= height: continue

            if grid[neighbor_y][neighbor_x] == '.':
                grid[neighbor_y][neighbor_x] = 'b'


def possible_to_add_mines_to_grid(mines, width, height):
    if mines >= width*height:
        return False, None

    unit = min(width, height)

    original_width = width
    original_height = height

    grid = create_empty_grid(width, height)

    while mines >= unit:
        mines -= unit
        if width > height:
            # unit = height
            # removing a column

            for i in xrange(height):
                add_mine(width-1, i, grid, original_width, original_height)

            width -= 1
        else:
            # unit = width
            # removing a row

            for i in xrange(width):
                add_mine(i, height-1, grid, original_width, original_height)

            height -= 1

        unit = min(width, height)

    return possible_to_add_mines_to_grid_recursive(mines, original_width, original_height, grid)

#@profile
def possible_to_add_mines_to_grid_recursive(mines, width, height, grid):
    if mines == 0:
        return grid_ok(grid, width, height), grid

    for option_x in xrange(width):
        for option_y in xrange(height):
            if grid[option_y][option_x] != '*':
                copy_grid = deepcopy(grid)
                add_mine(option_x, option_y, copy_grid, width, height)

                possible, result_grid = possible_to_add_mines_to_grid_recursive(mines - 1, width, height, copy_grid)
                if possible:
                    return True, result_grid

    return False, None


def calculate_for(width, height, mines):
    # assume mines < width and mines < height
    pass


# def calculate():
#
#     cache = {}
#
#             if frozenset((width, height)) not in cache:
#


def main():
    for case_number in xrange(int(raw_input())):

        r,c,m = read_list_of(int)
        possible, grid = possible_to_add_mines_to_grid(m, c,r)

        print 'Case #%d:' % (case_number + 1, )
        if possible:
            print format_grid(grid, c, r)
        else:
            print 'Impossible'

main()

# print ((possible_to_add_mines_to_grid(1, 2, 2, create_empty_grid(2, 2))[0] == False))
# print ((possible_to_add_mines_to_grid(2, 3, 3, create_empty_grid(3, 3))[0] == False))
# print ((possible_to_add_mines_to_grid(2, 2, 2, create_empty_grid(2, 2))[0] == False))
# print ((possible_to_add_mines_to_grid(25, 5,5, create_empty_grid(5, 5))[0] == False))
#
# print ((possible_to_add_mines_to_grid(1, 3, 3, create_empty_grid(3, 3))[0] == True))
# print format_grid(possible_to_add_mines_to_grid(1, 3, 3, create_empty_grid(3, 3))[1], 3 , 3)
#
# print ((possible_to_add_mines_to_grid(2, 4, 3, create_empty_grid(4, 3))[0] == True))
# print format_grid(possible_to_add_mines_to_grid(2, 4, 3, create_empty_grid(4, 3))[1], 4, 3)
#
# print ((possible_to_add_mines_to_grid(3, 4, 3, create_empty_grid(4, 3))[0] == True))
# print format_grid(possible_to_add_mines_to_grid(3, 4, 3, create_empty_grid(4, 3))[1], 4, 3)
#
# print ((possible_to_add_mines_to_grid(3, 3, 3, create_empty_grid(3, 3))[0] == True))
# print format_grid(possible_to_add_mines_to_grid(3, 3, 3, create_empty_grid(3, 3))[1], 3, 3)
#
# print ((possible_to_add_mines_to_grid(24, 5,5, create_empty_grid(5, 5))[0] == True))
# print format_grid(possible_to_add_mines_to_grid(24, 5,5, create_empty_grid(5, 5))[1], 5, 5)

# possible, grid = possible_to_add_mines_to_grid(5, 10,10, create_empty_grid(10, 10))
# print possible
# print format_grid(grid, 10, 10)

# possible, grid = possible_to_add_mines_to_grid(9, 2,5)
# print possible
# print format_grid(grid, 2, 5)