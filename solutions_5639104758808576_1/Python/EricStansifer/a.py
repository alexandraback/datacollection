from common import *

def main(casenum):
    n, s = readline().split()
    n = int(n)

    needed = 0
    cum = 0

    for i in range(n + 1):
        needed = max(needed, i - cum)
        cum += int(s[i])

    writecase(casenum, needed)

run(main)
