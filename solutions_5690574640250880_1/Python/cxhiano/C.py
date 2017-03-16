import sys

def log(msg):
    sys.stderr.write(str(msg) + '\n')

def solve(r, c, m):
    field = []
    for x in range(r):
        tmp = []
        for y in range(c):
            tmp.append('*')
        field.append(tmp)
    empties = r * c - m
    if empties == 1:
        field[0][0] = 'c'
        return field
    if r == 1 or c == 1:
        for x in range(r):
            for y in range(c):
                if empties > 0:
                    field[x][y] = '.'
                    empties -= 1
        field[0][0] = 'c'
        return field

    for h in range(2, r + 1):
        w = empties / h
        remain = empties % h

        if w < 2:
            break

        if w > c or (remain >= w and h < r):
            continue

        for x in range(h):
            for y in range(w):
                field[x][y] = '.'

        if remain != 1:
            if h < r:
                for y in range(remain):
                    field[h][y] = '.'
            else:
                for x in range(remain):
                    field[x][w] = '.'
            field[0][0] = 'c'
            return field
        elif h > 2 and w > 2:
            if h < r:
                field[h][0] = field[h][1] = '.'
            else:
                field[0][w] = field[1][w] = '.'
            field[h - 1][w - 1] = '*'
            field[0][0] = 'c'
            return field
        for x in range(r):
            for y in range(c):
                field[x][y] = '*'

    return 'Impossible'

if __name__ == '__main__':
    T = int(raw_input())
    for t in range(T):
        r, c, m = map(int, raw_input().split())
        ans = solve(r, c, m)
        print 'Case #{0}:'.format(t + 1)
        if type(ans) == list:
            for line in ans:
                for item in line:
                    sys.stdout.write(item)
                print ''
        else:
            log('{0} {1} {2} {3}'.format(r, c, m, r * c - m))
            print ans
