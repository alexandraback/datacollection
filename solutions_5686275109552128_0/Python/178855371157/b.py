import sys

N = 1001

# S[k][i] = min number of moves to break a stack of i pancakes to stacks of <= k
S = [[0] * N for k in range(N)]
for k in range(1, N):
    for i in range(k+1, N):
        S[k][i] = N
        for j in range(1,i):
            S[k][i] = min(S[k][i], S[k][j] + S[k][i-j] + 1)
            
T = int(sys.stdin.readline())

for n in range(1, T+1):
    D = int(sys.stdin.readline())
    P = [int(p) for p in sys.stdin.readline().split()]     

    max_p = max(P)
    answer = max_p
    for k in range(1, max_p):
        answer = min(answer, k + sum([S[k][p] for p in P]))
        
    # P.sort(reverse=True)
    # answer = P[0]
    # steps = 0
    # while P[0] > 1:
    #     a = (P[0] + 1) / 2
    #     b = P[0] / 2
    #     P[0] = a
    #     P.append(b)
    #     P.sort(reverse=True)
    #     steps += 1
    #     answer = min(answer, P[0] + steps)        
    # answer = min(answer, 1 + steps)
        
    print "Case #{}: {}".format(n, answer)
