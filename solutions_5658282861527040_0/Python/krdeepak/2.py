import sys
import os

if __name__ == '__main__':

    cases = int(sys.stdin.readline())

    for i in xrange(cases):
        A, B, K = [int(x) for x in sys.stdin.readline().split()]
        count = 0
        
        for x in xrange(0, A):
            for y in xrange(0, B):
                if x&y < K:
                    count += 1

        sys.stdout.write('Case #{0}: {1}\n'.format(i+1, count))
