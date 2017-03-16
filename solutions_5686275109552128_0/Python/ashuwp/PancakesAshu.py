__author__ = 'Ashutosh'

import sys
import math

if __name__ == '__main__':
    for tc in range(int(sys.stdin.readline())):
        keeper = int(sys.stdin.readline())
        tx = sorted(map(int, sys.stdin.readline().split()), reverse=True)
        a = tx[0]
        b = float('inf')
        for r in range(1, a + 1):
            c = 0
            for plate in tx:
                if plate <= r:
                    break
                c += math.ceil(plate / r) - 1
            if c + r < b:
                b = c + r
        print('Case #%d: %d' % (tc + 1, b))