import sys

T = int(sys.stdin.readline())

def f(levels):
    stars = 0
    numLevels = len(levels)
    n = 0

    while stars < numLevels*2:
        key = -1
        best = -1

        for l in levels.iterkeys():
            (a,b) = levels[l]

            if b <= stars and best < 2:
                n += 1
                best = 2
                key = l
            elif a <= stars and best < 1:
                n += 1
                best = 1
                key = l

        if key == -1:
            return "Too Bad"
        else:
            if best == 2:
                stars += 2
                del levels[key]
            else:
                (a_,b_) = levels[key]
                levels[key] = (99999,b_)
                stars += 1

    return n


for i in range(1,T+1):
    N = int(sys.stdin.readline())

    levels = [None]*N
    for j in range(0,N):
        line = sys.stdin.readline().split()
        levels[j] = (int(line[0]), int(line[1]))

    levels_ = {}
    q = 0
    for l in sorted(levels, key=lambda x: x[1]):
        levels_[q] = l
        q += 1

    print "Case %d: %s" % (i, f(levels_))
