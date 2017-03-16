R, N, M, K = 0, 0, 0, 0
A = []

def fact(n):
    ret = {}
    for i in range(2, n):
        if i * i > n:
            break
        if n % i != 0:
            continue
        ret[i] = 0
        while n % i == 0:
            ret[i] += 1
            n = int(n / i)
    if n > 1:
        ret[n] = 1
    return ret

def solve():
    cand = []
    for a in A:
        cand.append(fact(a))
    has = {}
    for c in cand:
        no2 = False
        for f, n in c.items():
            if f == 2 and n >= 3:
                no2 = True
            if f == 2 and n == 1:
                has[2] = n
            if f == 3:
                has[3] = n
            if f == 5:
                has[5] = n
        ok = 2 in c
        mx = 0
        for f, n in c.items():
            if f == 2 and n % 2 != 0:
                ok = False
            if f == 2 and n % 2 == 0:
                mx = max(mx, int(n / 2))
        if ok:
            has[4] = mx
    ret = ''
    for h, n in has.items():
        if no2:
            continue
        for i in range(n):
            ret += str(h)
            if len(ret) == 3:
                break
    if len(ret) != 3:
        ret = '222'
    return ret

input()
R, N, M, K = list(map(int, input().split(' ' )))
print('Case #1:')
for i in range(R):
    A = list(map(int, input().split(' ')))
    print(solve())
