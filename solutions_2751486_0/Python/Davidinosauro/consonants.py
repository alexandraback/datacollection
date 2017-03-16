#!python
from __future__ import print_function

import sys
from collections import deque
from math import log, floor

VOWELS = set('aeiou')

def result(name, n):
    l = len(name)
    res = 0
    prev_group = 0 # index just after the first letter of previous group
    num_cons = 0
    for j in range(n):
        if name[j] not in VOWELS:
            num_cons += 1

    for i in range(l - n + 1):
        j = i + n - 1
        if num_cons == n:
            # res += num sottostringhe che contengono questo gruppo ma non
            # il precedente
            res += (i - prev_group + 1) * (l - j)
            prev_group = i + 1

        if j + 1 < l: # if this is not the last loop
            num_cons += ((-1 if name[i] not in VOWELS else 0) +
                         (1 if name[j+1] not in VOWELS else 0))
    return res

if __name__ == '__main__':
    T = int(sys.stdin.readline().strip())
    #print('T:', repr(T))
    for t in range(T):
        name, n = sys.stdin.readline().strip().split(' ')
        print("Case #{}: {}".format(str(t+1), result(name, int(n))))

