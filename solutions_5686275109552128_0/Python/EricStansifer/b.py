from common import *

def main(casenum):
    d = readint()
    ps = readints()

    best = 10000

    for i in range(1, 1002):
        cur = i
        for p in ps:
            cur += ((p - 1) // i)
        best = min(best, cur)

    writecase(casenum, best)

run(main)
