
def solve_case(case):
    r, c, m = case
    free = r * c - m

    if free <= 0:
        raise ValueError('Yikes!')

    grid = []

    if r == 1:
        row = 'c'
        for i in range(1, c - m):
            row += '.'
        for i in range(0, m):
            row += '*'
        grid.append(row)
        return '\n'.join(grid)
    
    if c == 1:
        grid.append('c')
        for i in range(1, r - m):
            grid.append('.')
        for i in range(0, m):
            grid.append('*')
        return '\n'.join(grid)

    if free == 1:
        row = 'c'
        for i in range(1, c):
            row += '*'
        grid.append(row)
        for i in range(1, r):
            row = ''
            for j in range(0, c):
                row += '*'
            grid.append(row)
        return '\n'.join(grid)

    if free != 2:
        if r == 2:
            if m % 2 == 1:
                return 'Impossible'

            m_row = m / 2
            f_row = c - m_row

            row = ''
            for i in range(0, m_row):
                row += '*'
            for i in range(0, f_row):
                row += '.'
            for i in range(0, r - 1):
                grid.append(row)
            grid.append(row[:-1] + 'c')
            return '\n'.join(grid)

        if c == 2:
            if m % 2 == 1:
                return 'Impossible'

            m_col = m / 2
            f_col = r - m_col

            row = ''
            for i in range(0, c):
                row += '*'
            for i in range(0, m_col):
                grid.append(row)
            row = ''
            for i in range(0, c):
                row += '.'
            for i in range(0, f_col - 1):
                grid.append(row)
            grid.append('c' + row[1:])
            return '\n'.join(grid)

    if free in [2, 3, 5, 7]:
        return 'Impossible'

    root = is_square(free)
    if root is not False and root <= r and root <= c:
        row = ''
        for i in range(0, root):
            row += '.'
        for i in range(root, c):
            row += '*'
        grid.append('c' + row[1:])
        for i in range(1, root):
            grid.append(row)

        row = ''
        for i in range(0, c):
            row += '*'
        for i in range(root, r):
            grid.append(row)
        return '\n'.join(grid)
    
    if r < c:
        d_l = r
        d_w = free / r
        d_r = free % r

        if d_w == 1:
            new_dl = free / 2
            new_dw = free / new_dl
            new_dr = free % new_dl

            if new_dr == 0:
                row = ''
                for i in range(0, new_dw):
                    row += '.'
                for i in range(new_dw, c):
                    row += '*'
                grid.append('c' + row[1:])
                for i in range(1, new_dl):
                    grid.append(row)

                row = ''
                for i in range(0, c):
                    row += '*'
                for i in range(new_dl, r):
                    grid.append(row)

                return '\n'.join(grid)

        if d_r == 0:
            row = ''
            for i in range(0, d_w):
                row += '.'
            for i in range(d_w, c):
                row += '*'
            grid.append('c' + row[1:])
            for i in range(1, r):
                grid.append(row)

            return '\n'.join(grid)
        
        elif d_r > 1:
            row = ''
            for i in range(0, d_w):
                row += '.'
            row += '.'
            for i in range(d_w + 1, c):
                row += '*'
            grid.append('c' + row[1:])
            for i in range(1, d_r):
                grid.append(row)

            row = ''
            for i in range(0, d_w):
                row += '.'
            for i in range(d_w, c):
                row += '*'
            for i in range(d_r, r):
                grid.append(row)
                
            return '\n'.join(grid)

        else:
            if d_w == 2:
                row = ''
                for i in range(0, d_w):
                    row += '.'
                row += '.'
                for i in range(d_w + 1, c):
                    row += '*'
                grid.append('c' + row[1:])
                for i in range(0, d_r + 1):
                    grid.append(row)

                row = ''
                for i in range(0, d_w):
                    row += '.'
                for i in range(d_w, c):
                    row += '*'
                for i in range(d_r, r - 3):
                    grid.append(row)

                row = ''
                for i in range(0, c):
                    row += '*'
                grid.append(row)

                return '\n'.join(grid)
            
            elif d_w > 2:
                row = ''
                for i in range(0, d_w):
                    row += '.'
                row += '.'
                for i in range(d_w + 1, c):
                    row += '*'
                grid.append('c' + row[1:])
                for i in range(0, d_r):
                    grid.append(row)

                row = ''
                for i in range(0, d_w):
                    row += '.'
                for i in range(d_w, c):
                    row += '*'
                for i in range(d_r, r - 2):
                    grid.append(row)

                row = ''
                for i in range(0, d_w - 1):
                    row += '.'
                for i in range(d_w - 1, c):
                    row += '*'
                grid.append(row)

                return '\n'.join(grid)
    else:
        d_w = c
        d_l = free / c
        d_r = free % c
        
        if d_l == 1:
            new_dw = free / 2
            new_dl = free / new_dw
            new_dr = free % new_dl

            if new_dr == 0:
                row = ''
                for i in range(0, new_dw):
                    row += '.'
                for i in range(new_dw, c):
                    row += '*'
                grid.append('c' + row[1:])
                for i in range(1, new_dl):
                    grid.append(row)

                row = ''
                for i in range(0, c):
                    row += '*'
                for i in range(new_dl, r):
                    grid.append(row)
                
                return '\n'.join(grid)

        if d_r == 0:
            row = ''
            for i in range(0, c):
                row += '.'
            grid.append('c' + row[1:])
            for i in range(1, d_l):
                grid.append(row)

            row = ''
            for i in range(0, c):
                row += '*'
            for i in range(d_l, r):
                grid.append(row)

            return '\n'.join(grid)

        elif d_r > 1:
            row = ''
            for i in range(0, c):
                row += '.'
            grid.append('c' + row[1:])
            for i in range(1, d_l):
                grid.append(row)

            row = ''
            for i in range(0, d_r):
                row += '.'
            for i in range(d_r, c):
                row += '*'
            grid.append(row)

            row = ''
            for i in range(0, c):
                row += '*'
            for i in range(d_l + 1, r):
                grid.append(row)

            return '\n'.join(grid)

        else:
            if d_l == 2:
                row = ''
                for i in range(0, c - 1):
                    row += '.'
                row += '*'
                grid.append('c' + row[1:])
                grid.append(row)

                row = ''
                for i in range(0, 3):
                    row += '.'
                for i in range(3, c):
                    row += '*'
                grid.append(row)

                row = ''
                for i in range(0, c):
                    row += '*'
                for i in range(3, r):
                    grid.append(row)

                return '\n'.join(grid)

            elif d_l > 2:
                row = ''
                for i in range(0, c):
                    row += '.'
                grid.append('c' + row[1:])
                for i in range(1, d_l - 1):
                    grid.append(row)

                row = ''
                for i in range(1, c):
                    row += '.'
                row += '*'
                grid.append(row)

                row = ''
                for i in range(0, 2):
                    row += '.'
                for i in range(2, c):
                    row += '*'
                grid.append(row)

                row = ''
                for i in range(0, c):
                    row += '*'
                for i in range(d_l, r - 1):
                    grid.append(row)
                return '\n'.join(grid)
                
        
    raise ValueError('Unknown')

def is_square(num):
    root = int(num ** 0.5)
    if num == root * root:
        return root
    return False

def parse(input_lines):
    n_cases = int(input_lines.pop(0))
    cases = []

    for i in range(0, len(input_lines)):
        if not input_lines[i]:
            continue
        cases.append([int(item) for item in input_lines[i].split(' ')])

    return n_cases, cases    

def solve(input_file):
    with open(input_file + '.in', 'r') as f:
        input_lines = f.read().split('\n')

    n_cases, cases = parse(input_lines)
    if n_cases != len(cases):
        raise ValueError('Unmatched cases!')

    solution = []
    for i in range(0, n_cases):
        answer = 'Case #%s:\n%s' % (i + 1, solve_case(cases[i]))
        solution.append(answer)
    
    with open(input_file + '.out', 'w') as f:
        for line in solution:
            f.write('%s\n' % line)        

if __name__ == '__main__':
    solve('C-small-attempt1')
    #solve('problem')
    #pass
