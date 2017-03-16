def go(S):
    S = S + '+'
    res = 0
    for i in range(1, len(S)):
        if S[i] != S[i-1]:
            res += 1
    return res

T = int(input())
for tc in range(T):
    S = input()
    print("Case #{}: {}".format(tc + 1, go(S)))