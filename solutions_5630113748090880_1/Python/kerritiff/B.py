def solve(n):
    ans = set()
    for i in range(2 * n - 1):
        s = map(int, input().split())
        for x in s:
            if x in ans:
                ans.remove(x)
            else:
                ans.add(x)
    return ' '.join(map(str, sorted(list(ans))))

t = int(input())

for i in range(t):
    x = int(input())
    print('Case #%d: %s' % (i + 1, solve(x)))
