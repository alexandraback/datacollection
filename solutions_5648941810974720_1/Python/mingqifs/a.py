import sys
sys.setrecursionlimit(150000000)  # set the maximum depth as 1500
num_str = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
num = {}
res = []
for i in range(10):
    num[i] = {}
    for c in num_str[i]:
        num[i].setdefault(c, 0)
        num[i][c] += 1

def check(d, x):
    for k in num[x]:
        if k not in d or d[k] < num[x][k]:
            return False
    return True

def success(d):
    for k in d:
        if d[k] != 0:
            return False
    return True
def mink(d,x):
    c = 100000000
    for k in num[x]:
        c = min(c, d[k] // num[x][k])
    return c

def work(d, x):
    if x < 0:
        return
    if success(d):
        return True
    if check(d, x):
        f = 1
        if x == 0 : f = mink(d,x)
        for k in num[x]:
            d[k] -= f * num[x][k]
        if work(d, x):
            global res
            res.append(str(x))
            return True
        for k in num[x]:
            d[k] += f * num[x][k]

    if work(d, x-1):
        return True



T = int(input())
for case in range(1, T + 1):
    print(case, file=sys.stderr)
    s = input()
    d = {}
    res = []
    for c in s:
        d.setdefault(c, 0)
        d[c] += 1
    work(d, 9)
    res.sort()
    print('Case #{0}: {1}'.format(case, ''.join(res)))

