from itertools import product
from functools import lru_cache


# @lru_cache(maxsize=None)
def memo(x, res):
    if x == b-1:
        return 1
    return sum([memo(i) for i in range(x+1, b) if res[x][i]])

def nthbit(n,b):
    res = (((b//(2**x))%2) == 1)
    # print(n, b, res)
    return res

nc = int(input())
for tc in range(1, nc+1):
    b, m = [int(x) for x in input().split()]
    if m > 2**(b-2):
        print("Case #{}: IMPOSSIBLE".format(str(tc)))
        continue
    if m == 2**(b-2):
        res = [[j > i for j in range(b)] for i in range(b)]
        foo = [['1' if x else '0' for x in l] for l in res]
        print("Case #{}: POSSIBLE".format(str(tc)))
        [print(''.join(x)) for x in foo]
        continue
    res = [[j > i for j in range(b)] for i in range(b)]
    for x in range(0, b):
        res[0][b-x-1] = nthbit(x, m)

    res[0] = res[0][1:] + [False]
    foo = [['1' if x else '0' for x in l] for l in res]
    print("Case #{}: POSSIBLE".format(str(tc)))
    [print(''.join(x)) for x in foo]
    # print('\n'.join([str(x) for x in res]))
    # for x in product([True, False], repeat=(b**2-b)//2):
    #     x = list(x)
    #     for i,a in enumerate(res):
    #         for j, b in enumerate(a):
    #             if j>i:
    #                 res[i][j]=x[-1]
    #                 x.pop()
    #     if memo(0, res) == m:
    #         break
    # else:
    #     raise ValueError