import random

def fact(i):
    if i==0: return 1
    else: return i * fact(i-1)

def choose(n,i):
    if i<0 or i>n: return 0
    else: return fact(n) / (fact(i) * fact(n-i))

def base(n,b):
    if (n < b): return [n]
    else:
        l = base(n/b, b)
        l.append(n%b)
        return l

def expmod(x,y,n):
    if y==0: return 1
    elif y%2 == 1: return (x * expmod(x,y-1,n)) % n
    else: return expmod(x, y/2, n)**2 % n

def pseudo_prime(n): return 1 == expmod(2, n-1, n)
def prime(n):
    if n<=3: return n > 1
    found = False
    for i in range(1,101):
        a = random.randint(1,n-1)
        x = expmod(a, (n-1)/2, n)
        if x==1: continue
        elif x==n-1: found = True
        else: return False
    return found


def fib(n, cache={0:1, 1:1}, cache_max=1):
    for i in xrange(cache_max+1, n+1):
        cache[i] = cache[i-1] + cache[i-2]
    return cache[n]

def int_sqrt(n):
    if n <= 1: return n
    low = 0
    high = n
    while(True):
        if high == low+1: return low
        mid = (high+low)/2
        if mid*mid <= n:
            low = mid
        else:
            high = mid
################################################################
def f(n):
    return int(.5*n*n + 1.5*n + 1.001)

################################################################
def solve():
    N,X,Y = [int(x) for x in input.readline().split(' ')]
    X = abs(X)
    h = X+Y # height of center of top diamond in completed triangle
    if N >= f(h):
        return 1.0
    if N < f(h-2) or X == 0:
        return 0.0
    n = N - f(h-2)
    # If there are n extras, and our property is at height Y,
    # we need at least y+1 to fall on our side...
    # Also, we know only h will fit in each side
    if n >= Y + h + 1: # Check!
        return 1.0
    return sum([choose(n, k) for k in range(Y+1,n+1)]) * .5**n
################################################################

from datetime import datetime
time_start = datetime.today()
def now(): return datetime.today() - time_start

import sys
infilename = sys.argv[1]
outfilename = infilename.replace('.in','.out')

input = open(sys.argv[1], 'r')
output = open(sys.argv[1].replace('.in','.out'), 'w')
n = int(input.readline())

for i in range(1,n+1):
    result = solve()
    print "Case #%d: %s \t %s" % (i, result, now())
    output.write("Case #%d: %s\n" % (i, result))
    output.flush()
