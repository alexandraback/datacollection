__author__ = 'Ashutosh'

import sys

def get(k, i):
    return ord(k[i]) - ord('0')

if __name__ == '__main__':
    tcc = int(sys.stdin.readline())
    for tc in range(tcc):
        [ms, arr] = sys.stdin.readline().split()
        ms = int(ms)
        p = 0
        f = 0
        for i in range(ms + 1):
            j = get(arr, i)
            if j != 0:
                if p < i:
                    f += i - p
                    p = i
                p += j
        print('Case #%d: %d' % (tc + 1, f))