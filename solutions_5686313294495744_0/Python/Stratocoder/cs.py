from collections import Counter

t = int(raw_input())

for tt in xrange(1, t + 1):
    n = int(raw_input())
    w1 = Counter()
    w2 = Counter()
    tp = []
    for i in xrange(n):
        tw1, tw2 = raw_input().split(' ')
        w1.update([tw1])
        w2.update([tw2])
        tp.append((tw1, tw2))

    ans = 0
    for i in xrange(2 ** n):
        mp = bin(i)[2:]
        mp = '0' * (n - len(mp)) + mp
        wc1 = w1.copy()
        wc2 = w2.copy()
        ct = 0
        for j in xrange(n):
            if mp[j] == '0':
                ct += 1
                wc1.subtract([tp[j][0]])
                wc2.subtract([tp[j][1]])
        if sorted(wc1.values())[0] and sorted(wc2.values())[0]:
            ans = max(ans, ct)
    print "Case #{}: {}".format(tt, ans)
