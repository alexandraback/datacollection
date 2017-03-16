import math

N = 16
J = 50


def isprime(n):
    l = int(math.sqrt(n))
    l = min(l, 100)
    if n == l:
        l -= 1
    for i in range(2, l + 1):
        if n % i == 0:
            return i
    return None

def check(x):
    l = []
    for k in range(2, 11):
        cur = int(x, k)
        d = isprime(cur)
        if d is None:
            return None
        l.append(d)
    return l

def nxt(x):
    um = 1
    k = N - 2
    while (k > 0) and (um > 0):
        if (x[k] == '0'):
            um = 0
            x = x[:k] + '1' + x[k+1:]
        else:
            x = x[:k] + '0' + x[k+1:]
        k -= 1
    return x


x = (N - 2) * '0'
x = '1' + x + '1'

print "Case #1:"

while J > 0:
    c = check(x)
    if not (c is None):
        print x,
        for i in c:
            print i,
        print
        J -= 1
    x = nxt(x)
