from sys import stdin


_readstr  = lambda: stdin.readline().strip()
_readlist = lambda: stdin.readline().split()
_readint  = lambda: int(_readstr())


for n in range(_readint()):
    c, f, x = map(float, _readlist())

    t = 0
    v = 2
    r = float('inf')

    while t + x / v < r:
        r  = t + x / v
        t += c / v
        v += f

    print('Case #{}: {}'.format(n + 1, r))
