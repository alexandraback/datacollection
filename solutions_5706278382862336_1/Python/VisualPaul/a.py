def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)
def solve(p, q):
    g = gcd(q, 2 ** 40)
    if q // g != 1:
        return -1
    p *= (2 ** 40 // g)
    res = 41
    while p > 0:
        p //= 2
        res -= 1
    return res
ans = []
with open('input.txt') as f:
    t = int(f.readline())
    for i in range(t):
        p, q = map(int, f.readline().strip().split('/'))
        g = gcd(p, q)
        p //= g
        q //= g
        ans.append(solve(p, q))
with open('output.txt', 'w') as f:
    for k in range(t):
        print('Case #{}: '.format(k + 1), end='', file=f)
        if ans[k] == -1:
            print('impossible', file=f)
        else:
            print(ans[k], file=f)
          