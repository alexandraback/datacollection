from fractions import gcd

T = int(input())

for test in range(T):
    J, P, S, K = tuple(map(int, input().split()))
    sinc = 1
    
    if P == 1 or P == 2:
        pinc = 1
    elif P == 3 or P==5 or P==7 or P==9:
        pinc = 2
    elif P == 4 or P==8 or P==10:
        pinc = 3
    else:
        pinc = 5
    
    jp = [[0 for a in range(P)] for b in range(J)]
    js = [[0 for a in range(S)] for b in range(J)]
    ps = [[0 for a in range(S)] for b in range(P)]
    outfits = []

    j = 0
    p = 0
    s = 0
    
    for iter in range(J*P*S):
        if jp[j][p] < K and js[j][s] < K and ps[p][s] < K:
            outfits.append([j,p,s])
            jp[j][p] += 1
            js[j][s] += 1
            ps[p][s] += 1
        p = (p + pinc) % P
        if gcd(P,S) > 1 and (iter + 1) % S == 0:
            p = (p + pinc) % P
        s = (s + sinc) % S
        if (iter + 1) % (P*S) == 0:
            s = (s + sinc) % S
            j += 1
    
    print('Case #' + str(test+1) + ': ' + str(len(outfits)))
    for outfit in outfits:
        print(str(outfit[0] + 1) + ' ' + str(outfit[1] + 1) + ' ' + str(outfit[2] + 1))