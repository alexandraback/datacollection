def out(ms):
    for line in ms:
        print ''.join(line)


def rod(R, C, M, ms):
    N = max(R, C)
    if N - M < 1:
        return False
    cnt = 0
    for i in xrange(R):
        for j in xrange(C):
            if cnt < M:
                cnt += 1
                ms[i][j] = '*'
    ms[R-1][C-1] = 'c'
    return True


def sol3(R, C, M):
    ms = [['.' for j in xrange(C)] for i in xrange(R)]
    if M == 0:
        ms[0][0] = 'c'
        out(ms)
        return

    if R < 2 or C < 2:
        if not rod(R, C, M, ms):
            print 'Impossible'
        else:
            out(ms)
        return

    if M == (R * C - 1):
        ms = [['*' for j in xrange(C)] for i in xrange(R)]
        ms[0][0] = 'c'
        out(ms)
        return

    if M > (R*C - 4):
        print 'Impossible'
        return

    rr, cc = R - 2, C - 2 
    if rr == 0:
        if (M % 2) != 0:
            print 'Impossible'
            return
        for i in range(2):
            for j in range(M/2):
                ms[i][j] = '*'
        ms[R-1][C-1] = 'c'
        out(ms)
        return
    elif cc == 0:
        if M % 2 != 0:
            print 'Impossible'
            return
        for i in range(M/2):
            for j in range(2):
                ms[i][j] = '*'
        ms[R-1][C-1] = 'c'
        out(ms)
        return

    if (M + 1) == (R * C - 4):
        print 'Impossible'
        return
    if rr > 0 and cc > 0:
        cnt = 0
        for i in xrange(rr):
            for j in xrange(cc):
                if cnt < M:
                    ms[i][j] = '*'
                    cnt += 1
        mm = M - cnt
        if mm > 0:
            rrr, ccc = rr, cc
            if mm % 2 != 0:
                if (mm + 1) > ((rr - 1) * 2 + (cc - 1) * 2):
                    print 'Impossible'
                    return
                mm += 1
                ms[rr-1][cc-1] = '.'
                rrr, ccc = rr - 1, cc - 1
            cnt = 0
            for i in range(rr, R):
                for j in range(min(mm/2, ccc)):
                    cnt += 1
                    ms[i][j] = '*'
            mm -= cnt
            if mm > 0:
                cnt = 0
                for i in range(min(mm/2, rrr)):
                    for j in range(cc, C):
                        cnt += 1
                        ms[i][j] = '*'
                mm -= cnt
        assert mm == 0
        ms[R-1][C-1] = 'c'
        out(ms)
        return

        
import sys
readline = sys.stdin.readline

tn = int(readline())
for i in xrange(1, tn + 1):
    r, c, m = map(int, readline().split(" "))
    # print '=' * 80
    print 'Case #{}:'.format(i)
    sol3(r, c, m)
