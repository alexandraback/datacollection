from collections import defaultdict

T = int(raw_input())
L = set()
N = 0
c = []
bffs = []
m = 0


def verify(s):
    global m
    s = [s[-1]] + s + [s[0]]
    for i in range(1, len(s) - 1):
        assert s[i - 1] == bffs[s[i]] or s[i + 1] == bffs[s[i]]
    m = max(m, len(s) - 2)


def solve2(i):
    global m, L, c
    b = bffs[i]
    print '   ' * len(c), i, b, c
    if c and b == c[0]:
        print '   ' * len(c), "Found full loop", c + [i]
        verify(c + [i])
    if c and b == c[-1]:
        L.remove(i)
        c.append(i)
        verify(c)
        print '   ' * len(c), "Found half loop", c
        solve()
        c.pop(-1)
        L.add(i)
    else:
        if b not in L:
            return
        L.remove(i)
        c.append(i)
        solve2(b)
        c.pop(-1)
        L.add(i)


def solve():
    l2 = set(L)
    for x in l2:
        # print "Start with", x
        solve2(x)
        assert L == l2
        # if m == N: return


for t in range(T):
    N = int(raw_input())
    counts = defaultdict(int)
    m = 0
    bffs = map(lambda x: int(x) - 1, raw_input().split())
    L = set(range(N))
    solve()
    print "Case #%d:" % (t + 1), m
    s = 0
