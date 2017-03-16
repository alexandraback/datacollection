import sys
import collections
t = int(sys.stdin.readline())
normalTriples = collections.defaultdict(list)
surprisingTriples = collections.defaultdict(list)

for i in xrange(11):
    for u in xrange(i, 11):
        for j in xrange(u, 11):
            if j - i > 2: break
            if j - i > 1:
                surprisingTriples[i+u+j].append((i,u,j))
            else:
                normalTriples[i+u+j].append((i,u,j))

for testNumber in xrange(1, t+1):
    line = sys.stdin.readline().strip()
    items = map(int, line.split())
    n, s, p = items[0], items[1], items[2]
    items = items[3:]
    dp = [[0 for u in xrange(n+11)] for i in xrange(n+11)]
    for i, item in enumerate(items):
        for prvUsed in xrange(0, s+1):
            for triple in normalTriples[item]:
                dp[i+1][prvUsed] = max(dp[i+1][prvUsed], dp[i][prvUsed] + int(triple[2] >= p))
            for triple in surprisingTriples[item]:
                dp[i+1][prvUsed + 1] = max(dp[i+1][prvUsed + 1], dp[i][prvUsed] + int(triple[2] >= p))

    print "Case #{0}: ".format(testNumber) + str(dp[n][s])

