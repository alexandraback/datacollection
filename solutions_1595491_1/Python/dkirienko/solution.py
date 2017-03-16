n = int(input())
for num in range(1, n + 1):
    S = list(map(int, input().split()))
    Surp = S[1]
    P = S[2]
    MinSum = P + 2 * max(P - 1, 0)
    S = sorted(S[3:])
    Ans = 0
    while len(S) > 0 and S[-1] >= MinSum:
        Ans += 1
        S.pop()
    MinSum = P + 2 * max(P - 2, 0)
    while Surp > 0 and len(S) > 0 and S[-1] >= MinSum:
        Ans += 1
        S.pop()
        Surp -= 1
    print("Case #" + str(num) + ":", Ans)

