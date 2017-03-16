
def at(s, i, n):
    return s[:i] + str(n) + s[i+1:]

def gen(a, b):
    comm = 0
    while comm < len(a) and a[comm] == b[comm] and a[comm] != '?':
        comm += 1
    if comm == len(a):
        return {(int(a), int(b))}
    res = set()
    if a[comm] == b[comm] == '?':
        for i in range(9):
            res.update(gen(at(a, comm, i), at(b, comm, i + 1)))
            res.update(gen(at(a, comm, i + 1), at(b, comm, i)))
        for i in range(10):
            res.update(gen(at(a, comm, i), at(b, comm, i)))
    elif a[comm] == '?':
        for i in range(10):
            res.update(gen(at(a, comm, i), b))
    elif b[comm] == '?':
        for i in range(10):
            res.update(gen(a, at(b, comm, i)))
    else:
        if a[comm] < b[comm]:
            return {(int(a.replace('?', '9')), int(b.replace('?', '0')))}
        else:
            return {(int(a.replace('?', '0')), int(b.replace('?', '9')))}
    return res

def best(sols):
    sols = list(sols)
    a, b = sols[0]
    diff = abs(a - b)
    for x, y in sols:
        if abs(x - y) < diff:
            diff = abs(x - y)
            a, b = x, y
        elif abs(x - y) == diff:
            if x < a:
                a, b = x, y
            elif x == a:
                b = min(b, y)
    return (a, b)

def solve(a, b):
    return best(gen(a, b))

def pad(a, n):
    return '0' * (n - len(str(a))) + str(a)

n = int(input())
for t in range(1, n + 1):
    a, b = [w.strip() for w in input().split()]
    x, y = solve(a, b)
    print("Case #{}: {} {}".format(t, pad(x, len(a)), pad(y, len(a))))
