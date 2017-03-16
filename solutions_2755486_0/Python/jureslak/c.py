from heapq import *

def fix_wall(wall, att):
    nw = list(wall)
    n = 0
    for w, e, s in att:
        h = False
#        print "Hitting", w, e, "with str", s,".",
        for j in range(2*w, 2*e+1):
            if wall[j] < s:
                nw[j] = max(nw[j], s)
                h = True
        if h: n+= 1
#        if h: print "Hit!",
#        print
#        print nw[:30]
    return nw, n

def attack(tr):
    wall = [0 for i in range(20000)]
    q = []
    for r in tr:
        heappush(q, r+[0])

    succ = 0
    att = []
    prevd = 0
    while len(q) > 0:
        # napademo
        t = heappop(q)
#        print "Attacking", t

        if prevd < t[0]:
            wall, s = fix_wall(wall, att)
            succ += s
            prevd = t[0]
            att = []

        att += [t[2:5]]

        t[-1] += 1 # count
        t[0] += t[5] # time
        t[2] += t[6] # dist
        t[3] += t[6] # dist
        t[4] += t[7] # str
        if t[-1] < t[1]:
            heappush(q, t)
#        print "-------------------------------"
    wall, s = fix_wall(wall, att)
    succ += s
    return succ

t = int(raw_input())
for c in range(t):
    tr = []
    tn = int(raw_input())
    for i in range(tn):
        tr += [map(int, raw_input().split())]

    print "Case #{}: {}".format(c+1, attack(tr))
