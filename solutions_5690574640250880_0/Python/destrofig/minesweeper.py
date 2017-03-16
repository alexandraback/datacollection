
import sys
import logging

def quartercircle_iterator(radius, height, width):
    row = 0
    col = radius
    for row in xrange(col):
        if row < height and col < width:
            yield (row, col)
    row = radius
    for col in xrange(radius, -1, -1):
        if row < height and col < width:
            yield (row, col)

def diag_iterator(height, width):
    for radius in xrange(max(height, width)*2+1):
        for row in xrange(radius+1):
            col = radius - row
            if row < height and col < width:
                yield (row, col)

def get_ans(height, width, mines):
    a, b = sorted([height, width])
    if a != height:
        swapped = True
        height, width = width, height
    else:
        swapped = False
    
    free_cells = height * width - mines
    field = [['?' for _ in xrange(width)] for _ in xrange(height)]
    if height == 1:
        #print field
        field[0][width-1] = 'c'
        for x in xrange(mines):
            field[0][x] = '*'
        for x in xrange(mines, width-1):
            field[0][x] = '.'
    elif free_cells == 1:
        field = [['c']]
        field[0] += ['*' for _ in xrange(width-1)]
        for _ in xrange(height-1):
            field += [['*' for _ in xrange(width)]]
    elif free_cells in (2,3):
        #logging.debug("free cell = 2. Impossible.")
        field = None
    else:
        #print field
        #print 'h,w', height, width
        for row_no in xrange(height):
            for col_no in xrange(width):
                #print 'r, c', row_no, col_no
                #print field
                
                field[row_no][col_no] = '*'
        #logging.debug("was %s cells", free_cells)
        assert free_cells >= 4
        for row in xrange(2):
            for col in xrange(2):
                field[row][col] = '.'
                #logging.debug("Removed %s, %s", row, col)
        field[0][0] = 'c'
        free_cells -= 4
        #logging.debug("Left %s cells", free_cells)
        if free_cells == 0:
            pass
        elif free_cells == 1:
            field = None
        else:
            for row in xrange(2):
                assert field[row][2] == '*'
                field[row][2] = '.'
                #logging.debug("Removed %s, %s", row, 2)
                #logging.debug("Left %s cells", free_cells)
            free_cells -= 2
            #logging.debug("Left %s cells", free_cells)
            if free_cells == 0:
                pass
            elif free_cells == 1:
                field = None
            else:
                if height > 2:
                    for col in xrange(2):
                        assert field[2][col] == '*'
                        field[2][col] = '.'
                        #logging.debug("Removed %s, %s", 2, col)
                    free_cells -= 2
                    #logging.debug("Left %s cells", free_cells)

                for col in xrange(3, width):
                    if free_cells < 2:
                        break
                    assert field[0][col] == field[1][col] == '*'
                    field[0][col] = '.'
                    #logging.debug("Removed %s, %s", 0, col)
                    field[1][col] = '.'
                    #logging.debug("Removed %s, %s", 1, col)
                    
                    free_cells -= 2
                    #logging.debug("Left %s cells", free_cells)
                    
                for row in xrange(3, height):
                    if free_cells < 2:
                        break
                    assert field[row][0] == field[row][1] == '*'
                    field[row][0] = '.'
                    #logging.debug("Removed %s, %s", row, 0)
                    field[row][1] = '.'
                    #logging.debug("Removed %s, %s", row, 1)
                    free_cells -= 2
                    #logging.debug("Left %s cells", free_cells)
                
                #print "height - 2, row -2 = ", height -2, width -2
                for row_offset, col_offset in diag_iterator(height-2, width-2):
                    if free_cells == 0:
                        break
                    row, col = row_offset + 2, col_offset + 2
                    #print "nulling %s %s" % (row, col)
                    assert field[row][col] == '*'
                    field[row][col] = '.'
                    #logging.debug("Removed %s, %s. Left %s", row, col)
                    free_cells -= 1
                    #logging.debug("Left %s cells", free_cells)
                
                #assert free_cells == 0
                #print free_cells
                if free_cells != 0:
                    #print field
                    assert height == 2 and free_cells == 1
                    field = None
                
                
        
    if field is not None:
        #print field
        if swapped:
            rows = [''.join(row[x] for row in field) for x in xrange(width)]
        else:
            rows = [''.join(row) for row in field]
        return '\n'.join(rows)
    return "Impossible"

def reveal(field, click_row, click_col, field_height, field_width):
    content = field[click_row][click_col]
    if content in ('*', 'x'):
        return
    neigh_mine_count = 0
    for dr in xrange(max(0, click_row-1), min(field_height, click_row+2)):
        for dc in xrange(max(0, click_col-1), min(field_width, click_col+2)):
            if field[dr][dc] == '*':
                neigh_mine_count += 1
                break
        if neigh_mine_count != 0:
            break
    field[click_row][click_col] = 'x'
    
    if neigh_mine_count == 0:
        for dr in xrange(max(0, click_row-1), min(field_height, click_row+2)):
            for dc in xrange(max(0, click_col-1), min(field_width, click_col+2)):
                if (dr, dc) != (click_row, click_col):
                    reveal(field, dr, dc, field_height, field_width)
         
        

def test_ans(height, width, mines, ans):
    if ans == 'Impossible':
        return True
    #print height, width, mines
    #print ans
    
    
    lines = ans.split('\n')
    assert all(c in ('.','*','c','\n') for c in ans)
    assert len(lines) == height
    assert all(len(line) == len(lines[0]) for line in lines)
    assert ans.count('c') == 1
    mines_in_ans = ans.count('*')
    #print mines_in_ans, mines
    #print ans
    assert mines_in_ans == mines
    
    field = []
    for line in lines:
        field.append(list(line))
    click_pos = None
    for row_no, row in enumerate(field):
        for col_no, col in enumerate(row):
            if col == 'c':
                click_pos = (row_no, col_no)
                break
        if click_pos:
            break
    click_row, click_col = click_pos
    reveal(field, click_row, click_col, height, width)
    for row in field:
        assert all(c in ('x', '*') for c in row)
    
    return True
     

def solve(fd):
    case_count = int(fd.readline())
    solution = []
    for case_no in xrange(1, case_count + 1):
        height, width, mines = map(int, fd.readline().split())
        logging.info("Processing case #%d: %s, %s, %s", case_no, height, width, mines)
        ans = get_ans(height, width, mines)
        test_ans(height, width, mines, ans)
        solution.append("Case #%d:\n%s" % (case_no, ans))
    return '\n'.join(solution  )
    
    

def main():
    logging.basicConfig(level=logging.DEBUG)
    if sys.argv[1:]:
        fn = sys.argv[1]
        with open(fn, 'r') as fd:
            res = solve(fd)
        print(res)
    else:
        test()


def test_one(height, width, mines, possible=True):
    out = None
    try:
        out = get_ans(height, width, mines)
        
        if possible:
            assert out != 'Impossible'
        correct = test_ans(height, width, mines, out) 
        assert correct
        return out
    except (AssertionError, Exception) as e:
        print out
        logging.exception("Test %s %s %s %s failed", height, width, mines, possible)
        raise


def test():
    
     

    # stock tests
    test_one(5, 5, 23, False)
    test_one(3, 1, 1)
    test_one(2, 2, 1, False)
    test_one(4, 7, 3)
    test_one(10, 10, 82)
    
    
    # my tests
    test_one(1, 2, 1)
    test_one(2, 1, 1)
    test_one(2, 2, 1, False)
    test_one(3, 4, 5, False)
    test_one(3, 2, 5)
    test_one(2,4,0)
    test_one(2,5,1, False) 
    
    
    test_one(2, 10, 14)
    test_one(2, 10, 15, False)
    test_one(10, 10, 96)
    test_one(10, 10, 90)
    test_one(10, 10, 89)
    
    test_one(4, 2, 4)
    test_one(3, 2, 5)
    
    max_h, max_w = 15, 15
    for height in xrange(1, max_h):
        for width in xrange(1, max_w):
            logging.debug("Testing %d %d", height, width)
            for mines in xrange(0, height*width-1):
                
                test_one(height, width, mines, None)
        
    
    print("Test ok")
    
    
if __name__ == '__main__':
    main()