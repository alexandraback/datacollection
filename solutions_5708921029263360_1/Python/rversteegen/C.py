def ints():
    return [int(x) for x in raw_input().strip().split()]

T = input()
for t in range(T):

    J, P, S, K = ints()

    cnt = J*P*min(K, S)
    #cnt = J * min(K, P * S) #min(J*P*K, J*P*S)
    #cnt = min(K,J)*min(K,P)*min(K,S)

    print "Case #%d: %d" %( t+1, cnt)
    x = 0

    pairsJP = [[0] * P for j in range(J)]
    pairsPS = [[0] * S for p in range(P)]
    pairsJS = [[0] * S for j in range(J)]

    PS = [[0] * S for p in range(P)]
    JS = [[0] * S for j in range(J)]
    lasts = 0
    for j in range(J):
        lasts += 1
        for p in range(P):
            Prow = PS[p]
            Jrow = JS[j]
            jp = 0
            # lll = lasts
            # for q in range(S):
            #     lasts = lll + q
            for y in range(S):
                s = (y + lasts +1) % S
                if Prow[s] < K and Jrow[s] < K:
                    Prow[s] += 1
                    Jrow[s] += 1
                    jp += 1

                    print j+1, p+1, s+1
                    x += 1
                    pairsJP[j][p] += 1
                    assert pairsJP[j][p] <= K
                    pairsJS[j][s] += 1
                    assert pairsJS[j][s] <= K
                    pairsPS[p][s] += 1
                    assert pairsPS[p][s] <= K

                    if jp == K:
                        break
            lasts = s
            #print jp

    #print x
    assert x == cnt
