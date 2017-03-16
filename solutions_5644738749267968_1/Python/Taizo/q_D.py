
# -*- coding: cp932 -*-

import sys
import math
import itertools

inputfile = "D-large.in"
f = open(inputfile)
sys.stdout = open(inputfile.replace(".in", ".txt"),'w')
tc_num = int(f.readline().rstrip())

for tc in range(tc_num):
    N = int(f.readline().rstrip())
    l = f.readline().split()
    ns = [float(l[i]) for i in range(N)]
    l = f.readline().split()
    ks = [float(l[i]) for i in range(N)]

    ns.sort()
    ks.sort()
    kso = ks[:]
    dw = 0
    w = 0
    while len(ns) > 0:
        cn = ns[0]
        if ns[0] < ks[0]: # この石で勝ち目なし.
            ns.remove(ns[0])
            ks.remove(ks[len(ks)-1])
        else:
            ns.remove(ns[0])
            ks.remove(ks[0])
            dw += 1
        
        ck = -1
        if cn > kso[len(kso)-1]: # K に勝ち目なし
            kso.remove(kso[0])
            w += 1
        else:
            for i in range(len(kso)):
                if kso[i] > cn:
                    kso.remove(kso[i])
                    break
                
            
    
        #ck = next(itertools.ifilter(lambda x:x >= ns, kso), -1)
            
    print("Case #" + str(tc+1) + ": " + str(dw) + " " + str(w))

   
