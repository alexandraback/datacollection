from math import ceil

def f(c, w):
    return ceil(c/w) + w - 1

t = int(input())
for tt in range(t):
    r, c, w = map(int, input().split())

    print("Case #{}: {}".format(tt+1, f(c, w)));
