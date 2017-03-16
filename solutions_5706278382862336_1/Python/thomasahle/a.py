import sys
from fractions import gcd
read = lambda t=int: list(map(t,sys.stdin.readline().split()))
T, = read()
for t in range(T):
    res = 0
    p, q = list(map(int,read(str)[0].split('/')))
    d = gcd(p, q)
    p //= d
    q //= d

    depth = 0
    while q % 2 == 0:
        depth += 1
        q //= 2

    if q != 1:
        print("Case #{}: impossible".format(t+1, res))
        continue

    if depth > 40:
        print("Case #{}: impossible".format(t+1, res))
        continue

    res = depth-(len(bin(p))-3)

    print("Case #{}: {}".format(t+1, res))
