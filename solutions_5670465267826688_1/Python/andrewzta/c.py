import sys

sys.stdin = open("C-large.in", "r")
sys.stdout = open("C-large.out", "w")

"""
mt = [
    [1, i, j, k],
    [i, -1, k, -j],
    [j, -k, -1, i]
    [k, j, -i, -1]
]
"""
mt = [
    [0, 1, 2, 3],
    [1, 4, 3, 6],
    [2, 7, 4, 1],
    [3, 2, 5, 4]
]

def mul(a, b):
    s = 0
    if a >= 4:
        s = 4 - s
        a -= 4
    if b >= 4:
        s = 4 - s
        b -= 4
    return (mt[a][b] + s) % 8


ijk = "!ijk"

tn = int(input())
for test in range(tn):
    l, n = map(int, input().split())
    s = input()
    a = []
    total = 0
    for i in s:
        a.append(ijk.find(i))
        total = mul(total, a[-1])

    cur = 0
    foundi = False
    foundj = False
    for totali in range(min(16, n)):
        for pi in range(l):
            cur = mul(cur, a[pi])
            if (not foundi) and (cur == 1):
                foundi = True
                cur = 0
            elif foundi and (not foundj) and (cur == 2):
                foundj = True
    ans = foundi and foundj
    if foundi and foundj:
        cur = 0
        per = 0
        for i in range(n):
            cur = mul(cur, total)
            if cur == 0:
                per = i + 1
                break
        if per != 0:
            n %= per
        cur = 0
        for i in range(n):
            cur = mul(cur, total)
        if cur != 4:
            ans = False


    print("Case #%d: %s" % (test + 1, "YES" if ans else "NO"))

