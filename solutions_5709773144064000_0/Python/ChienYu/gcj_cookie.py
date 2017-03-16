from sys import stdin

def each_case(line):
    C, F, X = (float(s) for s in line.split())
    if X*F > 2*C:
        N = int(X/C - 2/F)
    else:
        N = 0

    return sum(C/(2+n*F) for n in xrange(N)) + X/(2+N*F)

T = int(stdin.readline())
for t in xrange(T):
    print 'Case #{}: {:.8f}'.format(t+1, each_case(stdin.readline()))
stdin.close()
