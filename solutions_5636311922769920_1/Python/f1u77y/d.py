#! /usr/bin/python

t = int(input())
for nt in range(1, t + 1):
    k, c, s = map(int, input().split())
    if c * s >= k:
        i = 0
        ans = list()
        while i < k:
            ci = i
            i += 1
            for j in range(c - 1):
                if i < k:
                    ci = ci * k + i
                    i += 1
                else:
                    ci = ci * k
            ans.append(ci)
        print("Case #%d: %s" % (nt, ' '.join(map(lambda x: str(x + 1), ans))))
    else:
        print("Case #%d: %s" % (nt, "IMPOSSIBLE"))
