
# -*- coding: utf8 -*-

import sys
import random

# inputFile = "C-sample.in"
inputFile = "C-small-attempt5.in"
# inputFile = "C-small-attempt1.in"
# inputFile = "C-large.in"
f = open(inputFile)
sys.stdout = open(inputFile.replace(".in", ".txt"), 'w')
tc_num = int(f.readline().rstrip())

for tc in range(tc_num):
    l = f.readline().split()
    j = int(l[0])
    p = int(l[1])
    s = int(l[2])
    kn = int(l[3])

    ans = []
    combJP = {}
    combJS = {}
    combPS = {}
    empty = {}

    lst = []

    slast = 0
    plast = 0
    poff = 0
    soff = 0
    for k in range(kn + 1):
        for jn in range(j):
            for pind in range(p):
                pn = (pind + poff) % p
                # pn = pind
                for sind in range(s):
                    sn = (sind + soff) % s

                    if combJP.get(jn, empty).get(pn, 0) >= k:
                        continue
                    if combJS.get(jn, empty).get(sn, 0) >= k:
                        continue
                    if combPS.get(pn, empty).get(sn, 0) >= k:
                        continue

                    slast = sn
                    plast = pn

                    if jn not in combJP:
                        combJP[jn] = {}
                    if jn not in combJS:
                        combJS[jn] = {}
                    if pn not in combPS:
                        combPS[pn] = {}

                    if pn not in combJP[jn]:
                        combJP[jn][pn] = 1
                    else:
                        combJP[jn][pn] += 1

                    if sn not in combJS[jn]:
                        combJS[jn][sn] = 1
                    else:
                        combJS[jn][sn] += 1

                    if sn not in combPS[pn]:
                        combPS[pn][sn] = 1
                    else:
                        combPS[pn][sn] += 1

                    ans.append(str(jn+1) + " " + str(pn + 1) + " " + str(sn + 1))
                soff = (slast + 1) % s
            poff = (plast + 1) % p

    print("Case #" + str(tc + 1) + ": " + str(len(ans)))

    for i in ans:
        print(i)
