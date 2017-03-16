""" 
Code Jam 2013
Problem: Pogo
Usages: 
  $ python script < input > output
  PS > gc input | python script | sc output.
"""

import sys

def naive(x, y):
    actions = ''
    if x >= 0:
        actions += 'WE'*x
    else:
        actions += 'EW'*(-x)
    if y >= 0:
        actions += 'SN'*y
    else:
        actions += 'NS'*(-y)
    return actions

if __name__ == '__main__':
    numcases = int(sys.stdin.readline().strip())
    for i in range(1, numcases+1):
        x, y = map(int, sys.stdin.readline().strip().split())
        result = naive(x, y)
        print "Case #%d: %s" % (i, result)
