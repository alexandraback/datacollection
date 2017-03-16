from sys import stdin
import sys
if len(sys.argv) > 1:
    sys.stdout = open(sys.argv[1], 'w')

def each_case(hiker):
    hike = []
    for D, H, M in hiker:
        for h in xrange(H):
            hike.append((D, M+h))
    assert len(hike) <= 2
    if hike[0][1] < hike[1][1]:
        slow, fast = hike[1], hike[0]
    else:
        slow, fast = hike[0], hike[1]
    if (360-slow[0])*slow[1] >= (720-fast[0])*fast[1]:
        return 1
    else:
        return 0

T = int(stdin.readline())
for t in xrange(1,T+1):
    N = int(stdin.readline())
    hiker = []
    for n in xrange(N):
        hiker.append(map(int, stdin.readline().split()))
    print 'Case #{}: {}'.format(t, each_case(hiker))
