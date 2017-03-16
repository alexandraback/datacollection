from itertools import count

from sympy import isprime, divisors, factorint

N = 32
J = 500

def judge(n):
    f = factorint(n, limit=30)
    for k in f.keys():
        if k == 1 or k == n:
            break
        assert n % k == 0
        return k
    return False

def get_num(k, base):
    num = 1
    fac = base
    kk = k
    while kk != 0:
        num += (kk % 2)*fac
        kk //= 2
        fac *= base
    num += base**(N-1)
    return num

def test(k):
    div = []
    if k < 0 or k >= 2**(N-2):
        return False
    for base in range(2, 11):
        num = get_num(k, base)
        ret = judge(num)
        if ret:
            div.append(ret)
        else:
            return False
    return div

ans = []

for i in range(2**(N-2)):
    ret = test(i)
    if ret:
        ans.append((i, ret))
        # print(get_num(i, 10))
    if len(ans) >= J:
        break
print('Case #1:')
for n, div in ans:
    print(get_num(n, base=10), end=' ')
    for d in div:
        print(d, end=' ')
    print()
