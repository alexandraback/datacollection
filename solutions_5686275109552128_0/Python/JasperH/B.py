def timeUnder(p, i):
    return sum((x - 1) // i for x in p)

def solve():
    d = int(raw_input())
    assert 1 <= d
    p = [int(x) for x in raw_input().split()]
    assert all(x > 0 for x in p)
    assert len(p) == d
    return min(i+timeUnder(p, i) for i in range(1, max(p) + 1))

for i in range(int(raw_input())):
    print "Case #%d: %d"%(i+1,solve())
