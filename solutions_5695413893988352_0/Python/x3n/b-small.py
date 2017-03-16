import re

def conform(n, pat):
    n_str = str(n).zfill(len(pat))

    for c1, c2 in zip(n_str, pat):
        if c2 != '?' and c1 != c2:
            return False

    return True

def solve(c, j):
    n = len(c)

    mdiff = 1000
    s1, s2 = 0, 0

    for k in range(0, 10 ** n):
        for t in range(0, 10 ** n):
            if conform(k, c) and conform(t, j):
                if abs(k - t) < mdiff:
                    mdiff = abs(k - t)
                    s1, s2 = k, t

    return (str(s1).zfill(n), str(s2).zfill(n))

t = int(input())

for i in range(t):
    c, j = input().split()
    print("Case #{0}: {1} {2}".format(i + 1, *solve(c, j)))
