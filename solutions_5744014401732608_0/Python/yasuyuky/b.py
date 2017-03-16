import sys
from itertools import combinations, permutations
from math import factorial

T = int(sys.stdin.readline())

# P = [ [0 for _ in range(51)] for _ in range(51)]
S = [ 0 for _ in range(51)]

# for i in range(51):
#     P[i][0] = 1
#     S[i] = 1
#     for j in range(1,i+1):
#         P[i][j] = P[i-1][j-1] + P[i-1][j]
#         S[i] += P[i][j]

for i in range(1,51):
    S[i] = S[i-1] + factorial(i)
# for i in range(51):
#     print(" ".join(map(str,P[i])))
# print(S)

# print(S)

for t in range(T):
    A = [ [0 for _ in range(51)] for _ in range(51)]

    B,M = [int(x) for x in sys.stdin.readline().split()]
    b = B-2
    if B == 2:
        if M > 1:
            print("Case #{}: IMPOSSIBLE".format(t+1))
        else:
            print("Case #{}: POSSIBLE".format(t+1))
            print("01\n00")
    elif S[b]<M:
        print("Case #{}: IMPOSSIBLE".format(t+1))
    else:
        print("Case #{}: POSSIBLE".format(t+1))
        count = 0
        for node in range(b):
            cs = [[1]+list (c)+[B] for c in permutations(range(2,B),node)]
            for comb in cs:
                pairs = list(zip(comb,comb[1:]))
                for x,y in pairs:
                    A[x][y] = 1
                count += 1
                if count == M:
                    break
            else:
                continue
            break
        for row in range(1,B+1):
            print("".join(str(x) for x in A[row][1:B+1]))
