from random import randint

t = int(input())
n, j = map(int, input().split())

used = set()
ans = dict()

def good(v):
    z = []
    for b in range(2, 11):
        nv = 0
        for x in v:
            nv = nv * b + x
        found = False
        for d in range(2, 10000):
            if d < nv and nv % d == 0:
                found = True
                z.append(d)
                break
        if not found: 
            return None
    return z

for x in range(j):
    while True:
        v = [1]
        for i in range(1, n - 1):
            v.append(randint(0, 1))
        v.append(1)
        v = tuple(v)
        z = good(v)
        if z is not None and v not in used:
            used.add(v)
            ans[v] = z
            break

print("Case #1:")
for v in used:
    print("".join(map(str, v)), " ".join(map(str, ans[v])))
            
