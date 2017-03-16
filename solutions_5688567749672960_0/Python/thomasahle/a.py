import sys
read = lambda t=int: list(map(t,sys.stdin.readline().split()))
array = lambda *ds: [array(*ds[1:]) for _ in range(ds[0])] if ds else 0

l = [0, 1]
for k in range(2,10**6+1):
    best = l[k-1] + 1
    if k % 10 != 0:
        rev = int(str(k)[::-1])
        if rev < k:
            best = min(best, l[rev] + 1)
    l.append(best)

# print(l[:50])

T, = read()
for t in range(T):
    N, = read()
    print("Case #{}: {}".format(t+1, l[N]))
