from math import ceil
T = int(raw_input())

for t in xrange(T):
    D = int(raw_input())
    P = [int(c) for c in raw_input().split(' ')]
    best = max(P)
    for h in range(1, max(P)):
        num_cuts = sum(int(ceil(float(p - h) / h)) for p in P if p > h)
        best = min(best, num_cuts + h)
    print 'Case #' + str(t + 1) + ': ' + str(best)
        
