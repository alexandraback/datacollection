#!/usr/bin/env python
import decimal
f = open('D-small-attempt1.in','r')
lines = f.readlines()
f.close()
tests = int(lines.pop(0).strip())



def play_war(N, naomi, ken):
    res=0
    naomi.sort()
    ken.sort()
    for i in range(N):
        naom = naomi.pop(0)
        ke = [ x for x in ken if x>naom ]
        if len(ke)==0:
            ke = ken.pop(0)
        else:
            ke = ke.pop(0)
            ken.remove(ke)
        if naom > ke:
            res+=1
    return res

def play_Dwar(N, naomi, ken):
    res=0
    naomi.sort()
    ken.sort()
    for i in range(N):
        if naomi[-1]<ken[-1]:
            naom_s = ken[-1]-decimal.Decimal(0.000001)
            naom = naomi.pop(0)
            ke = ken.pop()

        else:
            naom_s = ken[-1]+decimal.Decimal(0.000001)
            naom = [ x for x in naomi if x>ken[0] ][0]
            naomi.remove(naom)
            ke = ken.pop(0)
        if naom > ke:
            res+=1

    return res



for test in range(1,tests+1):
    N = int(lines.pop(0).strip())
    naomi = [ decimal.Decimal(x) for x in lines.pop(0).strip().split(" ") ]
    ken = [ decimal.Decimal(x) for x in lines.pop(0).strip().split(" ") ]

    print("Case #%s: %s %s" % (test, play_Dwar(N,list(naomi), list(ken)), play_war(N,list(naomi), list(ken))))
