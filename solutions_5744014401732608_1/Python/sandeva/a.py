import sys


def f(B, M):
    if 2 ** (B - 2) < M:
        return 'IMPOSSIBLE'
    elif 2 ** (B - 2) == M:
        b = '1' * (B - 1)
    else:
        b = ('0' * B + bin(M)[2:] + '0')[-(B - 1):]
    r = 'POSSIBLE\n0' + b + '\n'
    r += '\n'.join(['0' * (i + 1) + '1' * (B - i - 1) for i in range(1, B)])
    return r

with open(sys.argv[1]) as fi:
    for i, n in enumerate(fi.readlines()[1:]):
        print "Case #%d:" % (i + 1), f(*map(int, n.split()))
