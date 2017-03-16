T = int(input())
for t in range(1, T + 1):
    n = int(input())
    a = [int(x) for x in input().split()]
    m = max(a)
    r = float('inf')
    for i in range(1, m + 1):
        s = 0
        for v in a:
            s += (v - 1) // i
        r = min(r, s + i)
    print('Case #{}: {}'.format(t, r))
