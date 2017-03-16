import sys
from collections import defaultdict

def inter(w):
    n = len(w)
    for i in range(1,n):
        if w[i:] == w[:-i]:
            return i
    return n

def run(l1, keyb, target):
    k,l,s = [int(x) for x in l1.split()]
    # s is the length
    if l > s:
        return 0

    d = defaultdict(int)
    for i in keyb:
        d[i] += 1
    for t in target:
        if d[t] == 0:
            return 0
    probs = {}
    pr = 1.0
    for t in target:
        pr = pr * d[t] / k

    expected = pr*(s-l+1)
    nex = inter(target)
    m1 = 1 + (s-l) // nex

    return m1-expected

fin = open(sys.argv[1])
T = int(fin.readline().strip())
for i in range(1,T+1):
    line1 = fin.readline().strip()
    line2 = fin.readline().strip()
    line3 = fin.readline().strip()
    ans = run(line1, line2, line3)
    print('Case #%d: %.8f' % (i, ans))
