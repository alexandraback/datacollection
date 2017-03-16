def solve():
    H_MAX = 2510
    X = input()
    fs = [0] * H_MAX
    for i in range(X*2-1):
        for x in map(int, raw_input().split()):
            fs[x] += 1
    ans = []
    for i in range(H_MAX):
        if fs[i] % 2 == 1:
            ans.append(i)
    return ' '.join(map(str, ans))

T = input()
for i in range(1, T+1):
    ans = solve()
    print('Case #%d: %s' % (i, ans))
 
