from random import *
input()
print("Case #1:")
R, N, M, K = map(int, input().split())
for i in range(R):
    P = list(map(int, input().split()))
    max2 = 0
    max3 = 0
    max5 = 0
    for num in P:
        count2 = 0
        count3 = 0
        count5 = 0
        while num % 2 == 0:
            num //= 2
            count2 += 1
        while num % 3 == 0:
            num //= 3
            count3 += 1
        while num % 5 == 0:
            num //= 5
            count5 += 1
        max2 = max(max2, count2)
        max3 = max(max3, count3)
        max5 = max(max5, count5)
    Ans = [3] * max3 + [5] * max5
    Ans = [2] * (max2 % 2) + Ans + [4] * (max2 // 2)
    while 0 < len(Ans) < N - 1 and Ans[-1] == 4 and abs(Ans.count(2) - Ans.count(4)) > 1:
        Ans = [2, 2] + Ans[:-1]
    while len(Ans) < N:
        Ans.append(randint(2, M))
    Ans.sort()
    print("".join(map(str, Ans)))

