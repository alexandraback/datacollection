def conv(s, b):
    r, c = 0, 1
    while s > 0:
        r += c * (s % 10)
        c *= b
        s /= 10
    return r

trial = map(int, raw_input())
N, J = map(int, raw_input().split())
#N, J = 32, 500
print('Case #1:')

P = 10000
sieve = [True] * P
for i in range(2,P):
    for j in range(2*i,P,i):
        sieve[j] = False
p = []
for i in range(2,P):
    if sieve[i]: p.append(i)

m = 1 + (1 << (N - 1))

while True:
    v = []
    found = True
    r, s, t = m, 0, 1
    while r > 0:
        s += (r % 2) * t
        t *= 10
        r /= 2
    for d in range(2,11):
        ok = False
        q = conv(s, d);
        for x in p:
            if x * x > q: break
            if q % x == 0:
                ok = True
                v.append(x)
                break
        if ok == False:
            found = False
            break
    if found:
        print(s),
        for i in v: print(i),
        print('')
        J-=1
        if J == 0: break
    m += 2
