import sys, math

f = open(sys.argv[1])

N = int(f.readline())

def p(r, n):
    return n*(2*r+1)+2*n*(n-1)

for i in range(N):
    r, t = map(int, f.readline().split())

    res = int(math.floor(((1-2*r) + math.sqrt((2*r-1)**2 + 8*t))/4))

    while p(r, res) > t:
        res -= 1
    while p(r, res) <= t:
        res += 1
    res -= 1

#    print p(r, res) <= t < p(r, res+1)
    

    print 'Case #%d: %d' % (i+1, res)
