import sys
rl = lambda: sys.stdin.readline().strip()
T = int(rl())
for t in xrange(T):
    A, B = map(int, rl().split(' '))
    p = map(float, rl().split(' '))
    pi = 1
    s = 1 + B
    for i in xrange(A+1):
        # i - number of correct chars needed
        s = min(s, pi * (A + B - 2 * i) + (1 - pi) * (A + 2 * B - 2 * i + 1))
        if i < A:
            pi *= p[i]
    s += 1
    print "Case #" + str(t+1) + ": %.6f" % (s)
        
