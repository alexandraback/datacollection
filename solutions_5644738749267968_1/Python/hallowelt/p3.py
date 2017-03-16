#!/usr/bin/python

import sys

def warstrat(order, sym1, sym2):
    freen = 0
    wins = 0
    for i in order:
        if i == sym1:
            freen += 1
        if i == sym2:
            if freen > 0:
                freen -= 1
            else:
                wins += 1
    return wins

def war(order):
    return warstrat(order, 'n', 'k')
def deceitful(order):
    return len(order)/2 - warstrat(order, 'k', 'n')
    

cases = int(sys.stdin.readline())
for casenum in range(1, cases+1):
    sys.stdin.readline()
    n = [(float(i), 'n') for i in sys.stdin.readline().split()]
    k = [(float(i), 'k') for i in sys.stdin.readline().split()]
    nk = sorted(n + k, key=lambda pair: pair[0])
    order = [ar[1] for ar in nk]
    print 'Case #{}: {} {}'.format(casenum, deceitful(order), war(order))
