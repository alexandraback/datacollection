t = int(input())
for i in range(t):
    k, c, s = [int(i) for i in input().split()]
    print('Case #', i + 1, ': ', sep='', end='')
    if s < max(1, k - c + 1):
        print('IMPOSSIBLE')
    else:
        n = 0
        for i in range(k - s):
            n += i * (k ** (c - i - 1))
        for i in range(k - s, k - 1):
            print(n + i + 1, end=' ')
        print(n + k)