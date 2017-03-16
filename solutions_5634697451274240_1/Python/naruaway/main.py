def solve(s):
    i = len(s) - 1
    while i >= 0 and s[i] == '+':
        i -= 1
    if i < 0:
        return 0

    answer = 1
    c = s[i]
    while i >= 0:
        if c != s[i]:
            answer += 1
            c = s[i]
        i -= 1
    return answer


T = int(input())
for t in range(T):
    s = input()
    print('Case #{}: {}'.format(t + 1, solve(s)))
