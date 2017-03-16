import sys
import math
T = int(sys.stdin.readline())

for case in range(1, T + 1) :
    output = "Case #" + str(case) + ":"
    line = sys.stdin.readline().strip().split(" ")
    N = int(line[0])
    S = [ int (e) for e in line[1:]]

    dct = {0: []}

    exit = False
    for s in S:
        keys = dct.keys()
        for k in keys:
            item = dct[k]
            if (k + s) in dct:
                # bingo
                print output
                print " ".join([str(e) for e in dct[k + s]])
                print " ".join([str(e) for e in (dct[k] + [s,])])
                exit = True
                break
            else:
                dct[k + s] = item[:] + [s,]
        if exit:
            break
        dct[s] = [s,]

