def solve(s):
    res = 0 if s[-1] == '+' else 1
    last = s[0]
    for c in s:
        if c != last:
            res += 1
        last = c
    return res


t = int(input())

for i in range(t):
    s = input()
    print('Case #{}: {}'.format(i + 1, solve(s)))
