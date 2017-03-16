import sys
import collections

T = int(sys.stdin.readline())

for n in range(1, T+1):
    N = int(sys.stdin.readline())
    lines = []
    for i in range(1, 2*N):
        lines.append([int(x) for x in sys.stdin.readline().strip().split()])

    count = collections.defaultdict(int)
    for line in lines:
        for h in line:
            count[h] += 1

    odds = []
    for h in count:
        if count[h] % 2 != 0:
            odds.append(h)
    odds.sort()

    print "Case #{}: {}".format(n, ' '.join(str(h) for h in odds))
