import scipy.misc as sp

T = input()
for i in range(T):
    N, X, Y = [int(x) for x in raw_input().split()]
    if X < 0:
        X = -X
    step = X + Y
    total = 0
    for j in range(step/2):
        total += 4*j + 1
    if total + Y >= N:
        prob = 0
    elif Y == step:
        if total+2*step+1 <=N:
            prob = 1
        else:
            prob = 0
    elif total + step + 1 + Y <= N:
        prob = 1
    else:
        allcase = 0
        N -= total
        for j in range(Y, min(step, N)):
            allcase += sp.comb(N, j+1)
        totalcase = allcase
        for j in range(max(-1, N-step-1), Y):
            totalcase += sp.comb(N, j+1)
        prob = float(allcase)/totalcase
    print 'Case #'+str(i+1)+': '+str(prob) 
