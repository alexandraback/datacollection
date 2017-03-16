import sys
import math
import decimal

T = int(sys.stdin.readline())

for i in range(T):
    N = int(sys.stdin.readline())
    wall = [0]*(201*2)
    attacks = []
    succ = 0
    for j in range(N):
        di, ni, wi, ei, si, deltadi, deltapi, deltasi = \
                map(int, sys.stdin.readline().strip().split(' '))
        for n in range(0, ni):
            attacks.append( (di + n*deltadi, 
                wi + n*deltapi,
                ei + n*deltapi,
                si + n*deltasi) )
    #print attacks
    to_add = [0]*(201*2)
    cur_d = -1
    for a in sorted(attacks):
        cur_succ = 0
        if a[0] > cur_d:
            for ad in range(402):
                wall[ad] = max(wall[ad], to_add[ad])
            to_add = [0]*(201*2)
        for iw in range(max(0, ((a[1]+100)*2)), min(((a[2]+100)*2+1), 401)):
            if wall[iw] < a[3]:
                cur_succ = 1
                if to_add[iw] < a[3]:
                    to_add[iw] = a[3]
        succ += cur_succ
        cur_d = a[0]
        #print a, cur_succ, " ".join([str(idx) + ":" + str(v) for idx, v in enumerate(wall) if v != 0])
        #print a, cur_succ, " ".join([str(idx) + ":" + str(v) for idx, v in enumerate(to_add) if v != 0])
    
    print "Case #" + str(i+1) + ": " + str(succ)


