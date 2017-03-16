import sys

def InputIterator():
    for line in sys.stdin:
        for value in line.split(): yield value

inp = InputIterator()
T = int(next(inp))

for t in range(T):
    sys.stdout.write('Case #{0}:'.format(t+1))

    K, C, S = int(next(inp)), int(next(inp)), int(next(inp))

    if S < (K+C-1)//C:
        print(' IMPOSSIBLE')
    else:
        for i in range(0, K, C):
            cur = 0
            for j in range(C):
                d = K-C-i+j
                cur = K*cur + (0 if d < 0 else d)
            sys.stdout.write(' {0}'.format(cur+1))

        print()
