
# -*- coding: cp932 -*-

import sys

#inputFile = "D-sample.in"
#inputFile = "D-small-attempt0.in"
inputFile = "D-large.in"


f = open(inputFile)
sys.stdout = open(inputFile.replace(".in", ".txt"), 'w')
tc_num = int(f.readline().rstrip())


def solve(k, c, s):
    if c * s < k:
        return " IMPOSSIBLE"

    ans = []
    atten = 1

    while True:
        cur = atten
        atten += 1
        for fn in range(2, c+1):
            #sys.stderr.write("fn " + str(fn) + " atten = " + str(atten) + " curr = " + str(cur) + "\n")
            #print("fn " + str(fn) + " atten = " + str(atten) + " curr = " + str(cur))
            if atten > k:
                cur = (cur - 1) * k + 1
            else:
                cur = (cur - 1) * k + atten
                atten += 1

        ans.append(cur)
        if atten > k:
            break

    ansStr = ""
    for ansNum in ans:
        ansStr += " " + str(ansNum)

    return ansStr


for tc in range(tc_num):
    l = f.readline().split()
    K = int(l[0])
    C = int(l[1])
    S = int(l[2])

    print("Case #" + str(tc + 1) + ":" + solve(K, C, S))

