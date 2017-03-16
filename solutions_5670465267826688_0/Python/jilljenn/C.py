def neg(s):
    if len(s) == 2:
        return s[1]
    else:
        return "-" + s

def prod(a, b):
    p = {
        "1": {"1": "1", "i": "i",  "j": "j", "k": "k"},
        "i": {"1": "i", "i": "-1", "j": "k", "k": "-j"},
        "j": {"1": "j", "i": "-k", "j": "-1", "k": "i"},
        "k": {"1": "k", "i": "j",  "j": "-i", "k": "-1"},
    }
    l = p.keys()
    for i in l:
        p[neg(i)] = {}
        for j in l:
            p[i][neg(j)] = neg(p[i][j])
            p[neg(i)][j] = neg(p[i][j])
            p[neg(i)][neg(j)] = p[i][j]
    return p[a][b]

def power(a, n):
    if a == "1":
        return "1"
    elif a == "-1":
        return ["1", "-1"][n % 2]
    else:
        return ["1", a, "-1", neg(a)][n % 4]

T = int(raw_input())
for t in range(T):
    L, X = map(int, raw_input().split())
    s = raw_input()
    left = ["1"]
    right = ["1"]
    for _ in range(min(4, X)):
        for i in s:
            left.append(prod(left[-1], i))
    for _ in range(min(4, X)):
        for i in s[::-1]:
            right.append(prod(i, right[-1]))
    print 'Case #%d: %s' % (t + 1, "YES" if power(left[L], X) == "-1" and "i" in left and "k" in right and left.index("i") + right.index("k") < L * X else "NO")
