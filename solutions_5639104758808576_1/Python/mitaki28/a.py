T = int(input())
for t in range(1, T + 1):
    n, s = input().split()
    n = int(n)
    s = list(map(int, s))
    x = 0
    r = 0
    for i in range(n + 1):
        if x < i:
            r += i - x
            x = i
        x += s[i]
    print('Case #{}: {}'.format(t, r))
