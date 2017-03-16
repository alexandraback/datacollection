from random import randrange

def is_prime(n):
    if n <= 1:
        return False
    if n%2 == 0:
        return n == 2
    if n == 3:
        return True
    s = 0
    d = n - 1
    while d%2 == 0:
        d //= 2
        s += 1

    for i in range(10):
        a = randrange(2, n - 1)
        x = pow(a, d, n)
        if x == 1 or x == n - 1:
            continue
        for u in range(s - 1):
            x = (x*x)%n
            if x == 1:
                return False
            if x == n - 1:
                break
        else:
            return False

    return True

def sieve(n):
    l = [0]*(n+1)
    p = []
    for i in range(2, n+1):
        if l[i] == 0:
            for k in range(2*i, n+1, i):
                l[k] += 1
            p.append(i)
    return p, l

t = int(input())
assert(t == 1)
print("Case #1:")

primes, _ = sieve(10 ** 6)

n, j = map(int, input().split())
def generate():
    l = [1]
    for i in range(n - 2):
        l.append(randrange(2))
    l.append(1)
    return l

def ev(l, b):
    s = 0
    for x in l:
        s = s * b + x
    return s

def valid(l):
    for b in range(2, 11):
        if is_prime(ev(l, b)):
            return False
    return True

def witness(l):
    if not valid(l):
        return None
    witnesses = [None] * 9
    for b in range(2, 11):
        v = ev(l, b)
        for p in primes:
            if v % p == 0:
                break
        else:
            return None
        witnesses[b - 2] = p
    return witnesses

k = 0
seen = set()
while k < j:
    x = generate()
    w = witness(x)
    if w != None:
        s = "".join(str(u) for u in x)
        seen.add(s)
        k += 1
        print(s, " ".join(str(p) for p in w))

