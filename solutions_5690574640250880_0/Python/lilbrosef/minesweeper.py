import sys

saved_solutions = {}


def next_perm(v):
    t = (v | (v - 1)) + 1
    w = t | ((((t & -t) / (v & -v)) >> 1) - 1)
    return w


def element_0(c):
    return (1 << c) - 1


def gen_blocks(p, b):
    v = initial = element_0(p)
    block_mask = element_0(b)

    while (v >= initial):
        yield v
        v = next_perm(v) & block_mask


def is_zero(c, width, bombs):
    mask = (1 << width) - 1
    mask = mask << ((c / width) * width)
    c = 1 << c

    r = (c | (c << 1) | (c >> 1)) & mask
    r |= (r << width) | (r >> width)

    return (r & bombs) == 0


class Board(object):
    __slots__ = ('width', 'height', 'size', 'revealed', 'extended')

    def __init__(self, width, height, extended):
        self.width = width
        self.height = height
        self.size = width * height
        self.revealed = 0
        self.extended = extended

    def expand(self, bombs, click):
        self.revealed = 0
        self._expand(bombs, click)
        return self.revealed

    def _expand(self, bombs, click):
        if not 0 <= click < self.size:
            return
        width = self.width
        result = 1 << click
        if bombs & result or self.revealed & result:
            return
        self.revealed |= result

        if click % self.width == 0 and self.extended & 1:
            return

        if click / self.width == 0 and self.extended & 2:
            return

        if is_zero(click, width, bombs):
            if click % width < width - 1:
                self._expand(bombs, click + 1)
                self._expand(bombs, click + width + 1)
                self._expand(bombs, click - width + 1)
            if click % width > 0:
                self._expand(bombs, click - 1)
                self._expand(bombs, click + width - 1)
                self._expand(bombs, click - width - 1)
            self._expand(bombs, click + width)
            self._expand(bombs, click - width)

    def print_board(self, bombs):
        width = self.width
        height = self.height
        fmt = '{{0:0{0}b}}'.format(self.width)
        mask = (1 << width) - 1
        for i in range(height):
            print fmt.format((bombs >> (width * i)) & mask)

    def get_symbol(self, i, j, bombs, click):
        off = j + i * self.width
        x = 1 << off
        if x & bombs:
            return '*'
        if off == click:
            return 'c'
        return '.'


def bruteforce_one_click_solution(width, height, mines, extended):
    board = Board(width, height, extended)
    size = width * height
    for bombs in gen_blocks(mines, size):
        for click in range(1, size):
            if bombs & (1 << click):
                continue
            clicks = board.expand(bombs, click)
            if clicks ^ bombs == ((1 << size) - 1):
                return board, bombs, click
    return None, None, None


def cached_bruteforce_one_click_solution(width, height, mines, extended):
    global saved_solutions

    key = (width, height, mines, extended)
    solution = saved_solutions.get(key)
    if solution is None:
        solution = bruteforce_one_click_solution(
            width, height, mines, extended)
        saved_solutions[key] = solution
    return solution


def simplify_one_click_problem(width, height, mines):
    history = []
    extended = 0

    def produce_solution():
        w, h, m = history[-1]
        return cached_bruteforce_one_click_solution(w, h, m, extended)

    # prev_w, prev_h, prev_m = width, height, mines
    while True:
        history.append((width, height, mines))

        if width < height:
            width, height = height, width
            if mines < width or width < 3 or height < 3:
                return produce_solution()
                # Return solution
                pass
            else:
                mines -= width
                height -= 1
                extended |= 1
        else:
            if mines < height or width < 3 or height < 3:
                return produce_solution()
                # Return solution
                pass
            else:
                mines -= height
                width -= 1
                extended |= 2


def print_board(width, height, board, bombs, click):
    result = ''

    shift_i = width - board.width
    shift_j = height - board.height
    # print shift_i, shift_j
    for i in xrange(height):
        result += '\n'
        for j in xrange(width):
            if i < shift_i or j < shift_j:
                result += '*'
            else:
                result += board.get_symbol(
                    (i - shift_i), (j - shift_j),
                    bombs, click)
    # board.print_board(bombs)
    # print '-'
    # board.print_board(1 << click)
    print result[1:]


def print_empty_board(width, height):
    result = ''

    # print shift_i, shift_j
    for i in xrange(height):
        result += '\n'
        for j in xrange(width):
            result += '.'
    print 'c' + result[2:]


def main(filename):
    with open(filename) as fd:
        num_tests = int(fd.readline())
        for i in xrange(num_tests):
            h, w, m = [int(x) for x in fd.readline().split()]
            print 'Case #{0}:'.format(i + 1)
            if m == 0:
                print_empty_board(w, h)
                continue
            #board, bombs, click = simplify_one_click_problem(w, h, m)
            board, bombs, click = bruteforce_one_click_solution(w, h, m, False)

            if bombs is None:
                print 'Impossible'
            else:
                print_board(w, h, board, bombs, click)
                pass

if __name__ == '__main__':
    main(sys.argv[1])
