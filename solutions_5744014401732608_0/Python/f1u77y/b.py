#! /usr/bin/python

t = int(input())
for _ in range(1, t + 1):
    b, m = (int(i) for i in input().split())
    if m > 2 ** (b - 2):
        ans = "IMPOSSIBLE"
        a = []
    else:
        ans = "POSSIBLE"
        a = [['0' for j in range(b)] for i in range(b)]
        for i in range(b - 1):
            for j in range(i):
                a[j][i] = '1'
        if m == 2 ** (b - 2):
            a[0][b - 1] = '1'
            m -= 1
        for i in range(b - 2):
            if m & (1 << i):
                a[i + 1][b - 1] = '1'

    print("Case #%d: %s" % (_, ans))
    for s in a:
        print("".join(s))
    
