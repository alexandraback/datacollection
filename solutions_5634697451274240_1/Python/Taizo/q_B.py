
# -*- coding: cp932 -*-

import sys

#inputFile = "B-small-attempt0.in"
inputFile = "B-large.in"
#inputFile = "B-sample.in"
f = open(inputFile)
sys.stdout = open(inputFile.replace(".in", ".txt"), 'w')
tc_num = int(f.readline().rstrip())

for tc in range(tc_num):
    ps = f.readline().rstrip()
    cur = ps[0]
    ans = 0
    for c in ps:
        if c != cur:
            ans += 1
            cur = c
    if cur == '-':
        ans += 1

    print("Case #" + str(tc + 1) + ": " + str(ans))

