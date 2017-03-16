import sys
from numpy import array

def exp1(prob, total):
    p = prob.prod()
    n = len(prob)
    return (total - n + 1) * p + (2 * total + 2 - n) * (1 - p)

def exp2(prob, k, total):
    n = len(prob)
    p = prob[:(n-k)].prod()
    return ((total - n + 2 * k + 1) * p
            + (2 * total + 2 + 2 * k - n) * (1 - p))


s = sys.stdin.readlines()

T = int(s[0])
ss = (line.strip().split() for line in s[1:])

for t in range(T):
    A, B = map(int, ss.next())
    prob = array(map(float, ss.next()))
    m = B + 2
    m = min(m, exp1(prob, B))
    for i in range(1, A + 1):
        m = min(m, exp2(prob, i, B))
    print 'Case #' + str(t+1) + ':', m
