def solve(n):
    if n == 0:
        return 'INSOMNIA'
    seen = set()
    x = 0
    while len(seen) != 10:
        x += n
        seen.update(str(x))
    return x


t = int(input())

for i in range(t):
    n = int(input())
    print('Case #{}: {}'.format(i + 1, solve(n)))
