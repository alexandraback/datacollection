t = int(input())
for i in range(t):
    print('Case #{}: '.format(i+1), end='')
    s = input()
    cur = s[0]
    ans = 0
    for c in s:
        if c != cur:
            ans += 1
            cur = c
    if cur != '+':
        ans += 1
    print(ans)
