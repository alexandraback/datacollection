

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)

def solve(inp):
    p, q = inp[0], inp[1]
    
    t = 0
    while p < q:
        p *= 2
        t += 1
    
    assert p >= q, "Invalid"
    if t > 40:
        return "impossible"
    
    if p == q:
        return t
    else:
        r = 40-t
        p -= q
        while r > 0:
            if p == q:
                break
            p *= 2
            r -= 1
            if p > q:
                p -= q
    
        if r == 0 and p != q:
            return "impossible"
        else:
            return t

T = int(raw_input())
for t in xrange(1, T+1):
    inp = map(int, raw_input().strip().split("/"))
    print "Case #%d: %s" %(t, str(solve(inp)))
    