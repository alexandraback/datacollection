def pascal(n):
    pas = [2**(-n)]
    for i in xrange(1,n+1):
        pas.append(pas[-1]*(n+1-i)/i)
    return pas

full = []
for i in xrange(1,709):
    full.append(i*(2*i-1))
def find_s(x):
    s = 0
    for i in full:
        if x >= i:
            s += 1
        else:
            break
    return s





f = open('B-small-attempt0.in', 'r')
T = f.readline().strip()
T = int(T)

g = open('output-small0.txt', 'w')

for i in xrange(T):
    N, X, Y = [int(j) for j in f.readline().split()]
    s = find_s(N)
    if abs(X) + Y <= 2*(s-1):
        g.write('Case #%d: %f\n' % (i+1, 1.))
    elif abs(X) + Y >= 2*(s+1):
        g.write('Case #%d: %f\n' % (i+1, 0.))
    else:
        assert(abs(X) + Y == 2*s)
        n = N - s*(2*s-1)
        h = 2*s
        k = Y+1
        p = pascal(n)
        print n, h, k, p

        take = [(m <= n-k) or (m >= k+h) for m in xrange(n+1)]
        print take
        ans = 0
        for j,z in zip(p, take):
            if z:
                ans += j
        print ans
        
        if k > h:
            g.write('Case #%d: %f\n' % (i+1, 0.))
        else:
            g.write('Case #%d: %f\n' % (i+1, ans))
    
    


f.close()
g.close()
