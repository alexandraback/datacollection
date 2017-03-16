# -*- coding: utf-8 -*-

t = int(input())

for i in range(t):
    n = int(input())

    naomi = sorted(map(float, input().split()))
    ken = sorted(map(float, input().split()))

    na, nb = 0, n-1
    ka, kb = 0, n-1

    naomi_dec_points = 0
    naomi_war_points = 0
    while na <= nb:
        if ken[kb] < naomi[nb]:
            naomi_dec_points += 1
            nb -= 1
            kb -= 1
        else:
        #ken[kb] > naomi[nb]:
            na += 1
            kb -= 1

    na, nb = 0, n-1
    ka, kb = 0, n-1
    while na <= nb:
        if naomi[nb] < ken[kb]:
            nb -= 1
            kb -= 1
        else:
            naomi_war_points += 1
            ka += 1
            nb -= 1


    print("Case #%d: %d %d" % (i+1, naomi_dec_points, naomi_war_points))
    



