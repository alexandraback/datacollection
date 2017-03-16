def gcd(a, b):
    if b == 0: return a
    return gcd(b, a % b)

M = 2**40

n = int(raw_input())
for i in xrange(n):
    print "Case #" + str(i+1) + ":",

    a, b = map(int, raw_input().strip().split('/'))
    g = gcd(a, b)
    a /= g
    b /= g
    
    if b > M or M % b != 0:
        print "impossible"
        continue

    c = M / b * a
    print 40 - (len(bin(c)) - 3)
