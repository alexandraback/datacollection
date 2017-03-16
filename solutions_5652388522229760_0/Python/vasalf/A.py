#!/usr/bin/python3

t = int(input())
for i in range(t):
    n = int(input())
    if n == 0:
        print("Case #%d: INSOMNIA" % (n + 1))
        continue
    s = set(str(n))
    m = n
    while len(s) < 10:
        m += n
        for c in str(m):
            s.add(c)
    print("Case #%d: %d" % (i + 1, m))
