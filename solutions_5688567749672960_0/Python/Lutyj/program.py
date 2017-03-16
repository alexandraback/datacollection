import sys

def InputIterator():
    for line in sys.stdin:
        for value in line.split(): yield value

def calc(N):
    if N < 10:
        return N

    if (N % 10 == 0):
        return calc(N - 1) + 1

    NS = str(N)
    L = len(NS)
    N10 = int('1' + '0' * (L - 1))

    result = calc(N10)

    rev = 0
    for i in range(L):
        rev += 10 ** min(i, L - i - 1) * int(NS[i])

    return result + min(rev, N - N10)

inp = InputIterator()
T = int(next(inp))

for t in range(T):
    N = int(next(inp))
    print('Case #{0}:'.format(t + 1), calc(N))
