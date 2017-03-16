from math import ceil

def f(r, c, w):
    return ceil(c/w)*r + w - 1

t = int(input())
for tt in range(t):
    r, c, w = map(int, input().split())

    print("Case #{}: {}".format(tt+1, f(r, c, w)));
