import sys
import math
import numpy as np

T = int(sys.stdin.readline())
R, N, M, K = map(int, sys.stdin.readline().strip().split(' '))

print "Case #1:"
for i in range(R):
    knum = map(int, sys.stdin.readline().strip().split(' '))
    ret = []
    for p in knum:
        if p%125 == 0:
            for x in range(3 - ret.count(5)):
                ret.append(5)
        elif p%125 != 0 and p%25 == 0:
            for x in range(2 - ret.count(5)):
                ret.append(5)
        elif p%25 != 0 and p%5 == 0:
            for x in range(1 - ret.count(5)):
                ret.append(5)

        if p%27 == 0:
            for x in range(3 - ret.count(3)):
                ret.append(3)
        elif p%27 != 0 and p%9 == 0:
            for x in range(2 - ret.count(3)):
                ret.append(3)
        elif p%9 != 0 and p%3 == 0:
            for x in range(1 - ret.count(3)):
                ret.append(3)

        if p%64 == 0:
            for x in range(3 - ret.count(4)):
                ret.append(4)
    for p in knum:
        if p/np.prod(ret) == 16 and len(ret) == 0:
            ret = [4,2,2]
        elif p/np.prod(ret) == 16 and len(ret) == 1:
            ret.append(4)
            ret.append(4)
        elif p/np.prod(ret) == 4 and len(ret) == 2:
            ret.append(4)
        elif p/np.prod(ret) == 4 and len(ret) == 1:
            ret.append(2)
            ret.append(2)
        if np.prod(ret) < p and p/np.prod(ret) != 1 and p/np.prod(ret) < 6:
            if len(ret) < 3:
                ret.append(p/np.prod(ret))
    #while 1 in ret:
        #ret.remove(1)
    for x in range(N - len(ret)):
        ret.append(2)

    #print ret
    print ''.join(map(str, map(int, ret)))


