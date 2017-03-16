#!/usr/bin/python2.7

import sys

T = int(sys.stdin.readline())

for i in xrange(T):
    words = sys.stdin.readline().strip().split()
    J = int(words[0])
    P = int(words[1])
    S = int(words[2])
    K = int(words[3])
    com3 = J*P*S
    com2 = J*P

    outfits = []
    if com3 < com2*K:
        for j in xrange(0, J):
            for p in xrange(0, P):
                for s in xrange(0, S):
                    outfits.append([j,p,s])
    else:
        c_jp  = []
        c_ps  = []
        c_sj  = []
        c_jps = []
        for j in xrange(0, J):
            c_jp.append([0]*P)
        for p in xrange(0, P):
            c_ps.append([0]*S)
        for s in xrange(0, S):
            c_sj.append([0]*J)
        for j in xrange(0, J):
            tmp = []
            for p in xrange(0, P):
                tmp.append([0]*S)
            c_jps.append(tmp)

        for k in xrange(0, K):
            for j in xrange(0, J):
                for p in xrange(0, P):
                    min_s = K
                    id_s  = -1
                    for s in xrange(0, S):
                        if c_jp[j][p] < K and c_ps[p][s] < K and c_sj[s][j] < K and c_jps[j][p][s] == 0:
                            if c_ps[p][s] < min_s:
                                id_s  = s
                                min_s = c_ps[p][s]
                    if id_s >= 0:
                        c_jp[j][p] += 1
                        c_ps[p][id_s] += 1
                        c_sj[id_s][j] += 1
                        c_jps[j][p][id_s] += 1
                        outfits.append([j,p,id_s])
        

    print "Case #{0}: {1}".format((i+1), len(outfits))
    for of in outfits:
        print of[0]+1,of[1]+1,of[2]+1

    
