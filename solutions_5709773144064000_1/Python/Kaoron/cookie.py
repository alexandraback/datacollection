import fileinput

import itertools as it


lines = fileinput.input()
nb_cases = int(lines.next())


def print_result(n, res):
    print 'Case #%d: %s'%(n, res)

B = 2.0

for i in range(1, nb_cases+1):
    C, F, X = map(float,lines.next().strip().split())
    def rate(n): return (B+n*F)
    elapsed = 0
    for n in it.count():
        timefarm = C/rate(n)
        timenxt= X/rate(n+1)
        timen = X/rate(n)
        if timefarm+timenxt > timen :
            elapsed +=timen
            break
        else:
            elapsed += timefarm


    print_result(i,elapsed)

