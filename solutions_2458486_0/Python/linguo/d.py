# (d-small-attempt0.in) python is not fast enough for this code
# (d-small-attempt1.in) pypy is fast enough for this code

from sys import stdin

def getint():
    return int(stdin.readline())

def getints():
    return [int(z) for z in stdin.readline().split()]

for case in xrange(1,1+getint()):
    [nk, nc] = getints()
    keys = getints()
    chests = [getints() for i in xrange(nc)]
    chests = [(chest[0],chest[2:]) for chest in chests]
    canescape = [False] * (1 << len(chests))
    escaperoute = [-1] * (1 << len(chests))
    canescape[-1] = True
    for v in xrange((1 << len(chests)) - 2, -1, -1):
        keysnow = [z for z in keys]
        for i in xrange(nc):
            if (v >> i) & 1:
                keysnow += chests[i][1]
        ok = True
        for i in xrange(nc):
            if (v >> i) & 1:
                if chests[i][0] in keysnow:
                    index = keysnow.index(chests[i][0])
                    keysnow = keysnow[:index] + keysnow[(index+1):]
                else:
                    ok = False
                    break
        if ok:
            for i in xrange(nc):
                if ((v >> i) & 1) == 0:
                    if chests[i][0] in keysnow:
                        if canescape[v + (1 << i)]:
                            canescape[v] = True
                            escaperoute[v] = i
                            break
    if canescape[0]:
        order = []
        v = 0
        for i in xrange(nc):
            er = escaperoute[v]
            order += [er + 1]
            v += 1 << er
        print "Case #%d: %s" % (case, " ".join([str(er) for er in order]))
    else:
        print "Case #%d: IMPOSSIBLE" % (case,)
