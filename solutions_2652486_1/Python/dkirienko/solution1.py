from random import *
input()
print("Case #1:")
R, N, M, K = map(int, input().split())
for i in range(R):
    P = list(map(int, input().split()))
    max2 = 0
    max3 = 0
    max5 = 0
    max7 = 0
    for num in P:
        count2 = 0
        count3 = 0
        count5 = 0
        count7 = 0
        while num % 2 == 0:
            num //= 2
            count2 += 1
        while num % 3 == 0:
            num //= 3
            count3 += 1
        while num % 5 == 0:
            num //= 5
            count5 += 1
        while num % 7 == 0:
            num //= 7
            count7 += 1
        max2 = max(max2, count2)
        max3 = max(max3, count3)
        max5 = max(max5, count5)
        max5 = max(max7, count7)
    Ans = [3] * max3 + [5] * max5 + [7] * max7
    Ans = [2] * max2 + Ans
    while len(Ans) > N:
        if Ans.count(2) >= 3:
            if randint(0, 1) == 0:
                Ans = Ans[2:] + [4]
            else:
                Ans = Ans[3:] + [8]
        elif Ans.count(2) == 2:
            Ans = Ans[2:] + [4]
        elif Ans.count(4) > 0 and Ans.count(2) > 0:
            Ans = Ans + [8]
            Ans.pop(0)
            Ans.pop(Ans.index(4))
        elif Ans.count(4) >= 3:
            for x in range(3):
                Ans.pop(Ans.index(4))
            Ans = Ans + [8, 8]
    while len(Ans) < N:
        Ans.append(randint(2, M))
    Ans.sort()
    print("".join(map(str, Ans)))

