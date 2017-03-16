from collections import defaultdict

T = int(raw_input())

for t in xrange(T):
    N = int(raw_input())
    heights = defaultdict(int)
    for i in xrange(2*N - 1):
        l = [int(x) for x in raw_input().split()]
        for x in l:
            heights[x] += 1

    missing = []
    for h, c in heights.iteritems():
        if c % 2 == 1:
            missing.append(h)

    missing.sort()

    missing = [str(x) for x in missing]

    print "Case #" + str(t+1) + ": " + " ".join(missing)

