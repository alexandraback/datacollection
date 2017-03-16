#!/usr/bin/env python3.3
def concat_table(xs):
    return ''.join(list(map(lambda x: ''.join(x) + '\n', xs))).strip()

def place_mine_odd(table, r, c, m):
    place_mine_even(table, r, c, m+1)
    width = c-1
    for i in range(c):
        if table[-1][i] == '*':
            width = i-1
            break
    for i in range(-1, -r-1, -1):
        for j in range(width+1):
            if table[i][j] != '*':
                continue
            table[i][j] = '.'
            if j > 0:
                return
            table[i][j+1] = '.'
            for k in range(r):
                if table[k][width] == '.':
                    table[k][width] = '*'
                    if k == r-2:
                        table[k+1][width] = '*'
                        table[i][j+2] = '.'
                    return

def place_mine_even(table, r, c, m):
    count = 0
    for i in range(c):
        table[-1][i] = '.'
        table[-2][i] = '.'
        count += 2
        if count == (r*c -m):
            table[-1][0] = 'c'
            return

    for i in range(-3, -r-1, -1):
        for j in range(0, c-1, 2):
            table[i][j] = '.'
            table[i][j+1] = '.'
            count += 2
            if count == (r*c -m):
                table[-1][0] = 'c'
                return

    for i in range(-3, -r-1, -1):
        table[i][-1] = '.'
        count += 1
        if count == (r*c -m):
            table[-1][0] = 'c'
            return

def solve(r, c, m):
    table = [['*' for i in range(c)] for j in range(r)]
    if r*c - m == 1:
        table[-1][-1] = 'c'
        return concat_table(table)
    elif m == 0:
        table = [['.' for i in range(c)] for j in range(r)]
        table[-1][-1] = 'c'
        return concat_table(table)
    elif r == 1:
        for i in range(r*c-m):
          table[0][i] = '.'
        table[0][0] = 'c'
        return concat_table(table)
    elif c == 1:
        for i in range(r*c-m):
          table[i][0] = '.'
        table[0][0] = 'c'
        return concat_table(table)
    elif (r*c - m)%2 == 1:
        if (r*c - m) < 9:
            return 'Impossible'
        elif r < 3 or c < 3:
            return 'Impossible'
        else:
            place_mine_odd(table, r, c, m)
            return concat_table(table)
        return 'Impossible'
    elif (r*c - m) == 2:
        return 'Impossible'
    else:
        place_mine_even(table, r, c, m)
        return concat_table(table)

out_file = open('outputC.txt', 'w')
with open('C.in') as f:
    t = int(f.readline())
    for i in range(t):
        [r, c, m] = list(map(lambda x: int(x), f.readline().strip().split()))
        out_file.write('Case #' + str(i+1) + ':\n' + solve(r, c, m) + '\n')

out_file.close()
