tests = int(input())

for t in range(1, tests+1):
    b, m = map(int, input().split())
    if m > 2 ** (b - 2):
        print("Case #{}: IMPOSSIBLE".format(t))
        continue
    else:
        print("Case #{}: POSSIBLE".format(t))
    ans = [['0' for i in range(b)] for j in range(b)]
    for i in range(b - 1):
        for j in range(i):
            ans[j][i] = '1'
    here = 2 ** (b - 3)
    for j in range(b - 2, 0, -1):
        if here <= m:
            ans[j][b - 1] = '1'
            m -= here
        here //= 2
    if m:
        ans[0][b - 1] = '1'
    print('\n'.join(''.join(a) for a in ans))
