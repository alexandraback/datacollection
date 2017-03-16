import sys
read = lambda f=int: map(f, sys.stdin.readline().split())
array = lambda *ds: [array(*ds[1:]) for _ in range(ds[0])] if ds else 0

T, = read()
for t in range(T):
    sm, s = read(str)
    spare = 0
    extra = 0
    for i in range(int(sm)):
        spare += int(s[i])
        spare -= 1
        if spare == -1:
            extra += 1
            spare = 0
    print('Case #{}: {}'.format(t+1, extra))
