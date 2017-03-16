from copy import copy

def attacks(tribe):
    d,n,w,e,s,dd,de,ds = tribe
    attacks = [(d,w,e,s)]
    for i in xrange(n-1):
        d+=dd
        w+=de
        e+=de
        s+=ds
        attacks.append( (d,w,e,s) )
    return attacks

WMAX = 20000
WCENTER = WMAX / 2
for case in range(input()):
    print "Case #"+str(case+1)+":",
    T=int(raw_input())
    tribes = []
    for i in xrange(T):
        tribes.append(map(int,raw_input().split()))
    #print T
    atk = []
    for tribe in tribes:
        atk.extend(attacks(tribe))
    atk.sort()
    days = list(set([a[0] for a in atk]))
    days.sort()
    datk = {}
    for d in days:
        datk[d] = [a for a in atk if a[0] == d]
    #print days
    #print datk
    #print atk
    wall = [0 for i in xrange(WMAX)]
    success = 0
    for d in days:
        #print "day",d
        newwall = copy(wall)
        for a in datk[d]:
            d,w,e,s = a
            toadd = 0
            for i in xrange(w,e):
                if wall[i+WCENTER] < s:
                    newwall[i+WCENTER] = max(newwall[i+WCENTER],s)
                    toadd = 1
            success += toadd
            #print "toadd",a,toadd
        wall = newwall
        #print "".join(map(lambda x:str(x).rjust(2),wall[WCENTER-100:WCENTER+100]))
    print success
