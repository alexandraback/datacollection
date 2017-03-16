#!/usr/bin/python3
T = int(input())
for t in range(1,T+1):
    c, f, x = map(float, input().split())
    l = max(int(x/c-2/f), 0)
    s = c*sum((1/(2+n*f) for n in range(l)))
    print("Case #{}: {}".format(t, s + x/(2+l*f)))

