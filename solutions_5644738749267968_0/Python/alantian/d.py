#!/usr/bin/env python3

import math

def rl(T=str):
    return [ T(_) for _ in input().split() ]

def getWar( naomi, ken ):
    score = 0
    for naomiValue in naomi:
        s = [ i for i in range(len(ken)) if ken[i] > naomiValue ]
        if len(s) == 0:
            pick = 0
        else:
            pick = s[0]

        kenValue = ken[pick]
        ken = ken[:pick] + ken[pick+1:]

        if naomiValue > kenValue:
            score += 1
    return score

def getDWar( naomi, ken ):
    naomiPick = 0
    kenPick = 0
    score = 0
    
    while naomiPick < len(naomi):
        while naomiPick < len(naomi) and naomi[naomiPick] < ken[kenPick]:
            naomiPick += 1

        if naomiPick < len(naomi):
            score += 1
            naomiPick += 1
            kenPick += 1
    
    return score


T, *_ = rl(int)
for Case in range(1,T+1):
    n, *_ = rl(int)

    naomi = sorted( rl(float) )
    ken = sorted( rl(float) )

    dwar = getDWar( naomi, ken )
    war = getWar( naomi, ken )
    print( 'Case #%d: %d %d' % ( Case,dwar,war) )

