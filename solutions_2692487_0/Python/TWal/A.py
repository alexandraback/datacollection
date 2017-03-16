from copy import copy

def motes(A, mote):
    if mote == []:
        return 0
    maxMotel = filter(lambda x: x < A, mote)
    if maxMotel == []:
        if A == 1:
            del mote[mote.index(max(mote))]
            return 1 + motes(A, mote)
        else:
            test1 = 1 + motes(A + A - 1, copy(mote))
            del mote[mote.index(max(mote))]
            test2 = 1 + motes(A, mote)
            return min([test1, test2])

    maxMote = max(maxMotel)
    del mote[mote.index(maxMote)]

    return motes(A + maxMote, mote)


if __name__ == '__main__':
    nb = int(raw_input())
    for i in xrange(0, nb):
        A, N = map(int, raw_input().split())
        mote = map(int, raw_input().split())

        print "Case #" + str(i+1) + ": " + str(motes(A, mote))
