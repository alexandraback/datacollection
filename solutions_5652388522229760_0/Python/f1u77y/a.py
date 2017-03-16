#! /usr/bin/python

t = int(input())
for cn in range(t):
    n = int(input())
    if n == 0:
        print("CASE #%d: %s" % (cn + 1, "INSOMNIA"))
        continue
    m = n
    s = set()
    while len(s) < 10:
        s.update(set(str(n)))
        n += m
    print("CASE #%d: %d" % (cn + 1, n - m))
