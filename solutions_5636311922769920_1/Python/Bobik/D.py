def solve(k, c, s):
    if s * c < k:
        return 'IMPOSSIBLE'
    A = []
    for i in range((k + c - 1) // c):
        x = 0
        for j in range(c):
            x = x * k + (i * c + j) % k
        A.append(x + 1)
    return ' '.join(map(str, A))


t = int(input())

for i in range(t):
    k, c, s = map(int, input().split())
    print('Case #{}: {}'.format(i + 1, solve(k, c, s)))
