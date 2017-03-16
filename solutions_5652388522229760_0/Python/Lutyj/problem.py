import sys

def InputIterator():
    for line in sys.stdin:
        for value in line.split(): yield value

inp = InputIterator()
T = int(next(inp))

for t in range(T):
    sys.stdout.write('Case #{0}: '.format(t+1))

    n = int(next(inp))

    if n > 0:
        seen = [False] * 10

        i, n_seen = 0, 0
        while n_seen < 10:
            i += 1
            for d in str(i*n):
                d = ord(d) - ord('0')
                if not seen[d]:
                    seen[d] = True
                    n_seen += 1

        print(i*n)
    else:
        print('INSOMNIA')
