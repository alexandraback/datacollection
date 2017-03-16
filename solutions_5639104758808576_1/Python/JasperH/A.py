def solve():
    sin = raw_input().split()
    n = int(sin[0])
    l = [int(c) for c in sin[1]]
    assert len(l) == n + 1
    assert l[-1] > 0
    up = 0
    for i in range(n + 1):
        if up < i:
            assert up + 1 == i
            up += 1
        up += l[i]
    return up - sum(l)

cases = int(raw_input())
for i in range(cases):
    print "Case #%d: %d"%(i+1, solve())
