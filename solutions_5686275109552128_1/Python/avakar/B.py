import sys, heapq

input = sys.stdin.read().split()
def pop_int():
    return int(input.pop(0))

for t in xrange(pop_int()):
    D = pop_int()
    P = [pop_int() for i in xrange(D)]

    max_p = max(P)
    res = min(h + sum((p - 1) // h for p in P) for h in xrange(1, max_p+1))

    print 'Case #{}: {}'.format(t+1, res)
