from itertools import combinations


def sol():
    n = int(input())
    a = []
    b = []
    for i in range(n):
        w0, w1 = input().split(' ', 1)
        a.append(w0)
        b.append(w1)
    ans = 0
    for i in range(1, n):
        for l in combinations(range(n), i):
            sa = set()
            sb = set()
            valid = True
            for t in l:
                sa.add(a[t])
                sb.add(b[t])
            for j in range(n):
                if j not in l:
                    if a[j] in sa and b[j] in sb:
                        pass
                    else:
                        valid = False
                        break
            if valid:
                return n - i
    return 0


t = int(input())
for i in range(t):
    print("Case #%s: %s" % (i+1, sol()))
