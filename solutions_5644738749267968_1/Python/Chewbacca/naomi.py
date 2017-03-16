#! /usr/bin/env python3
from sys import stdin

def war(naomi, ken):
    wins=0
    for nao in naomi[::-1]:
        idx=1e10
        if ken[-1]>nao:
            # find the optimal
            for i in range(len(ken)):
                if ken[i]>nao:
                    del ken[i]
                    break
        else:
            wins+=1
            del ken[0]
    return wins

def deceitful(naomi, ken):
    wins=0
    while len(ken) > 0:
        if naomi[-1] > ken[0]:
            # tell ken told=0.999999999
            # yes, binary search would be better but who cares :-)
            for nao in naomi:
                if nao > ken[0]:
                    naomi.remove(nao)
                    del ken[0]
                    wins += 1
                    break
        else:
            break
    return wins
                
                


for case_no in range(1,int(stdin.readline())+1):
    N = int(stdin.readline())
    naomi = sorted(map(float,stdin.readline().split()))
    ken   = sorted(map(float,stdin.readline().split()))
    print("Case #{}: {} {}".format(
        case_no, 
        deceitful(naomi[:], ken[:]),
        war(naomi[:], ken[:]) ))

