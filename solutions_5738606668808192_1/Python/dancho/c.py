import random

def isprime(x):
    i = 2
    while i * i <= x:
        if x % i == 0:
            return False
        i += 1
    return True

def interp(seq, base):
    res = 0
    for x in seq:
        res = res * base + x;
    return res

def getcand(num, a):
    for k in a:
        if num % k == 0 and k < num:
            return k
    return -1

a = []
p = 2
while len(a) < 1000:
    if isprime(p):
        a += [p]
    p += 1

N = 32
J = 500
ans = []

while len(ans) < J:
    seq = [1] + [random.choice([0, 1]) for r in xrange(N - 2)] + [1]
    cand = []
    ok = True
    for b in xrange(2, 11):
        cnum = interp(seq, b)
        k = getcand(cnum, a)
        if k == -1:
            ok = False
            break
        else:
            cand += [k]
    if ok:
        ans += [(seq, cand)]

for aa in ans:
    print ''.join(map(str, aa[0])) + ' ' + ' '.join(map(str, aa[1]))
