
# -*- coding: cp932 -*-

import sys

#inputFile = "A-small-attempt0.in"
inputFile = "A-large.in"
#inputFile = "A-sample.in"
f = open(inputFile)
sys.stdout = open(inputFile.replace(".in", ".txt"), 'w')
tc_num = int(f.readline().rstrip())

for tc in range(tc_num):
    n = int(f.readline().rstrip())
    if n == 0:
        print("Case #" + str(tc + 1) + ": " + "INSOMNIA")
        continue

    remain = range(10)
    m = 0
    while len(remain) > 0:
        m += n
        mStr = str(m)
        for c in mStr:
            ic = int(c)
            if ic in remain:
                remain.remove(ic)

    print("Case #" + str(tc + 1) + ": " + str(m))

