from functools import lru_cache
import sys

sys.setrecursionlimit(10**7)

@lru_cache(maxsize=None)
def opt(n):

    if n == 1: return 1

    rev = int(''.join(reversed(str(n))))

    prev = n-1

    mmin = 10**100

    if rev < n and n % 10 != 0:
        mmin = min(mmin, opt(rev) + 1)

    mmin = min(opt(prev)+1, mmin)

    return mmin


testcases = int(input())

for i in range(1, 10**6):
    opt(i)


for i in range(1, testcases+1):
    n = int(input())

    print("Case #{}: {}".format(i, opt(n)))



# for i in range(1, n+1):
#     print("opt({}) = {}".format(i, opt(i)))