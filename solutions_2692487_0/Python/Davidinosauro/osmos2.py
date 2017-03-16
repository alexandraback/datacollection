#!python
from __future__ import print_function

import sys
from collections import deque
from math import log, floor

# armin, list, index of next mote, num_moves by now
def result(a, l, i):
    if i >= len(l):
        #print('finito')
        return 0
    mote = l[i]
    if mote < a:
        #print('mangio', mote)
        return result(a+mote, l, i+1)

    # if I delete all motes from this on
    delete_cost = len(l) - i

    if a == 1: #I can't eat nothing , so I must delete!
        return delete_cost

    # if I add motes until I can eat this
    add_cost = int(floor(log(float(mote-1)/(a-1), 2) + 1))
    #print('se mangio: a={}, mote={}'.format(2**add_cost * (a - 1) + 1, mote))

    #sys.exit(1)
    return min(
        delete_cost,
        add_cost + result(2**add_cost * (a - 1) + 1, l, i)
    )

if __name__ == '__main__':
    T = int(sys.stdin.readline().strip())
    #print('T:', repr(T))
    for t in range(T):
        a, n = [int(x) for x in sys.stdin.readline().strip().split(' ')]
        l = [int(x) for x in sys.stdin.readline().strip().split(' ')]
        l.sort()
        #print(l)
        #assert(len(l) == n)
        print("Case #{}: {}".format(str(t+1), result(a, l, 0)))

