import sys

def InputIterator():
    for line in sys.stdin:
        for value in line.split(): yield value

inp = InputIterator()
T = int(next(inp))

for t in range(T):
    C, F, X = float(next(inp)), float(next(inp)), float(next(inp))

    prev = X/2
    cur, k = 0, 1

    while True:
        cur += C / (2 + (k-1)*F)
        if (cur + X / (2 + k*F) >= prev): break
        prev = cur + X / (2 + k*F)
        k += 1

    print "Case #{0}: {1:0.7f}".format(t+1, prev)
