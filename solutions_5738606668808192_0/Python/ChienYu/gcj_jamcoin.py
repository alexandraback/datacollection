from sys import stdin

def each_case(N, J):
    j = 0
    for d1 in xrange(5, N, 2):
        for d2 in xrange(3, d1, 2):
            c = [0] * N
            c[0] = 1
            c[-1] = 1
            c[-d1] = 1
            c[-d2] = 1
            for d3 in xrange(4, N, 2):
                for d4 in xrange(2, d3, 2):
                    cc = c[:]
                    cc[-d3] = 1
                    cc[-d4] = 1
                    print ''.join(map(str, cc)) + ' 3 2 3 2 7 2 3 2 3'
                    j += 1
                    if j == J:
                        return

T = int(stdin.readline())
for t in xrange(1,T+1):
    N, J = map(int, stdin.readline().split())
    print 'Case #{}:'.format(t)
    each_case(N, J)