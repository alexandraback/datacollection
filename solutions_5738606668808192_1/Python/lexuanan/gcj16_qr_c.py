import math
import random

def sieve(n):
    b, p, ps = [True] * (n+1), 2, []
    for p in xrange(2, n+1):
        if b[p]:
            ps.append(p)
            for i in xrange(p, n+1, p):
                b[i] = False
    return ps

def primes(n):
    if type(n) != int:
        raise TypeError('must be integer')
    if n < 2:
        raise ValueError('must be greater than one')
    m = (n-1) // 2
    b = [True] * m
    i, p, ps = 0, 3, [2]
    while p*p < n:
        if b[i]:
            ps.append(p)
            j = 2*i*i + 6*i + 3
            while j < m:
                b[j] = False
                j = j + 2*i + 3
        i += 1; p += 2
    while i < m:
        if b[i]:
            ps.append(p)
        i += 1; p += 2
    return ps

def td_prime(n, limit=1000000):
    if type(n) != int:
        raise TypeError('must be integer')
    if n % 2 == 0:
        return n == 2
    d = 3
    while d * d <= n:
        if limit < d:
            raise OverflowError('limit exceeded')
        if n % d == 0:
            return False
        d += 2
    return True

def td_factors(n, limit=1000000):
    if type(n) != int:
        raise TypeError('must be integer')
    fs = []
    while n % 2 == 0:
        fs += [2]
        n /= 2
    if n == 1:
        return fs
    f = 3
    while f * f <= n:
        if limit < f:
            raise OverflowError('limit exceeded')
        if n % f == 0:
            fs += [f]
            n /= f
        else:
            f += 2
    return fs + [n]

def is_prime(n):
    if type(n) != int:
        print (n)
        raise TypeError('must be integer')
    if n < 2:
        return False
    ps = [2,3,5,7,11,13,17,19,23,29,31,37,41,
         43,47,53,59,61,67,71,73,79,83,89,97]
    def is_spsp(n, a):
        d, s = n-1, 0
        while d%2 == 0:
            d //= 2; s += 1
        t = pow(a,d,n)
        if t == 1:
            return True
        while s > 0:
            if t == n-1:
                return True
            t = (t*t) % n
            s -= 1
        return False
    if n in ps: return True
    for p in ps:
        if not is_spsp(n,p):
            return False
    return True

def rho_factors(n, limit=1000000):
    if type(n) != int:
        raise TypeError('must be integer')
    def gcd(a,b):
        while b: a, b = b, a%b
        return abs(a)
    def rho_factor(n, c, limit):
        f = lambda x: (x*x+c) % n
        t, h, d = 2, 2, 1
        while d == 1:
            if limit == 0:
                raise OverflowError('limit exceeded')
            t = f(t); h = f(f(h)); d = gcd(t-h, n)
        if d == n:
            return rho_factor(n, c+1, limit)
        if is_prime(d):
            return d
        return rho_factor(d, c+1, limit)
    if -1 <= n <= 1: return [n]
    if n < -1: return [-1] + rho_factors(-n, limit)
    fs = []
    while n % 2 == 0:
        n = n // 2; fs = fs + [2]
    if n == 1: return fs
    while not is_prime(n):
        f = rho_factor(n, 1, limit)
        n = n / f
        fs = fs + [f]
    return sorted(fs + [n])

def gcd(a,b):
    if b == 0:
        return a
    return gcd(b,a%b)

def brent(N):
        if N%2==0:
                return 2
        y,c,m = random.randint(1, N-1),random.randint(1, N-1),random.randint(1, N-1)
        g,r,q = 1,1,1
        while g==1:             
                x = y
                for i in range(r):
                        y = ((y*y)%N+c)%N
                k = 0
                while (k<r and g==1):
                        ys = y
                        for i in range(min(m,r-k)):
                                y = ((y*y)%N+c)%N
                                q = q*(abs(x-y))%N
                        g = gcd(q,N)
                        k = k + m
                r = r*2
        if g==N:
                while True:
                        ys = ((ys*ys)%N+c)%N
                        g = gcd(abs(x-ys),N)
                        if g>1:
                                break
         
        return g    

tong = 32
gioihan = 500
bound = 1<<tong
a = (1<<(tong-1))+1
dem = 0
outfile = open("C.out", "w")
outfile.write("Case #1:\n")
while a < bound:
    ok = 1
    for base in range(2,11):
        so = 0
        for i in range(tong-1,-1,-1):
            so = so * base
            if ((a >> i) & 1) == 1:
                so = so + 1
        if is_prime(so):
            ok = 0
            break
    if ok == 1:
        dem = dem + 1
        outfile.write("{0:b} ".format(a))
        for base in range(2,11):
            so = 0
            for i in range(tong-1,-1,-1):
                so = so * base
                if ((a >> i) & 1) == 1:
                    so = so + 1
            outfile.write("%d " % (brent(so)))
        outfile.write("\n")
        print ("done dem=%d" % (dem))
        if dem == gioihan:
            break
    a += 2
outfile.close()
