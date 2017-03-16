import itertools

def la(b, r):
    e = []
    for i in r:
        e.append([b] + i)
    return e

def bmg(k):
    if (k > 0):
        r = bmg(k - 1)
        return la(0, r) + la(1, r)
    return [[]]

def solve(p, bm):
    ans = 0
    ws1 = set()
    ws2 = set()
    for i in range(len(p)):
        w1, w2 = p[i]
        if bm[i] == 1:
            ws1.add(w1)
            ws2.add(w2)
        else:
            ans += 1
    for i in range(len(p)):
        w1, w2 = p[i]
        if bm[i] == 0:
            if not ((w1 in ws1) and (w2 in ws2)):
                return 0
    return ans

t = int(raw_input())

for test in range(t):
    print "Case #" + str(test + 1) + ":", 
    n = int(raw_input())
    p = []
    for i in range(n):
        word1, word2 = raw_input().split(' ')
        p.append((word1, word2))
    ans = 0
    for bm in bmg(len(p)):
        ans = max(ans, solve(p, bm))
    print ans
