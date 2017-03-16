import sys


def f(N):
    if not N:
        return "INSOMNIA"
    n = N
    s = set()
    while True:
        s |= set(map(int, str(n)))
        if len(s) == 10:
            break
        n += N
    return n

with open(sys.argv[1]) as fi:
    for i, n in enumerate(map(int, fi.readlines()[1:])):
        print "Case #%d:" % (i + 1), f(n)
