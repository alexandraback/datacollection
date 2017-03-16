import sys


def solve(R, C, M):
    ret = [['*']*C for _ in xrange(R)]
    ret[0][0] = 'c'
    empty = R * C - M
    if empty == 1: return ret
    if R == 1:
        for i in xrange(1, empty):
            ret[0][i] = '.'
        return ret
    if C == 1:
        for i in xrange(1, empty):
            ret[i][0] = '.'
        return ret 
    if R == 2 or C == 2:
        if empty == 1:
            return ret
        if empty == 2 or empty % 2 == 1:
            return None
        if R == 2:
            ret[1][0] = '.'
            for i in xrange(1, empty/2): 
                ret[0][i] = '.'
                ret[1][i] = '.'
        if C == 2:
            ret[0][1] = '.'
            for i in xrange(1, empty/2):
                ret[i][0] = '.'
                ret[i][1] = '.'
        return ret
    if empty == 2 or empty == 3 or empty == 5 or empty == 7:
        return None
    if empty / C < 3:
        size = empty / 3 
        for i in xrange(size):
            ret[0][i] = '.' 
            ret[1][i] = '.'
            ret[2][i] = '.'
        ret[0][0] = 'c'
        if empty % 3 == 2:
            ret[0][size] = '.'
            ret[1][size] = '.'
        elif empty % 3 == 1:
            ret[0][size] = '.'
            ret[1][size] = '.'
            ret[2][size-1] = '*'
    else:
        row_num = empty / C
        last_row = empty % C
        for i in xrange(row_num):
            for j in xrange(C):
                ret[i][j] = '.'
        for i in xrange(last_row):
            ret[row_num][i] = '.'
        ret[0][0] = 'c'
        if last_row == 1:
            ret[row_num][1] = '.'
            ret[row_num-1][C-1] = '*'
    return ret



if __name__ == '__main__':
    f = sys.stdin
    t = int(f.readline())
    for i in xrange(1, t+1):
        R, C, M = map(int, f.readline().split())
        print 'Case #%d:' % i
        ret = solve(R, C, M)
        if ret is None:
            print 'Impossible'
        else:
            for row in ret:
                print ''.join(row)    

