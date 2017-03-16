import random
T = int(input())
for case in range(1, T + 1):
    S = input()[::-1]
    cur = 0
    lans = ''
    rans = ''
    while cur < len(S):
        x = max(S[cur:])
        for i in range(cur, len(S)):
            if S[i] == x:
                if cur != i :
                    rans = S[cur:i][::-1] + rans
                lans += S[i]
                cur = i + 1
                break
    print("Case #{0}: {1}".format(case, lans + rans))



