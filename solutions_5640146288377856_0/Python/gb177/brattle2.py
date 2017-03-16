#!/usr/bin/python

# take 2
import sys
def N(): return tuple(map(int, raw_input().split()))

UNKNOWN = 0
HIT = 1
MISS = 2

def D(L):
    return [L[i+1] - L[i] for i in range(len(D)-1)]

T = N()[0]
for t in range(1, T + 1):
    R, C, W = N()
    if R != 1:
        print >> sys.stderr, "skipping R != 1"
        continue
    assert 1 <= C <= 10

    def find(v, L, start):
        while start < len(L):
            if L[start] == v:
                return start
            start += 1
        return -1

    def pprint(state):
        return "".join(["." if s == UNKNOWN else "H" if s == HIT else "M" for s in state])

    def shiprange(state):
        hit = find(HIT, state, 0)
        if hit != -1:
            p = hit
            while p >= 0 and state[p] != MISS:
                p -= 1
            minl = p + 1

            p = hit + 1
            while p < min(hit + W, C) and state[p] != MISS:
                p += 1
            maxl = p
            return minl, maxl
        else:
            misspos = [-1] + [ i for i, v in enumerate(state) if v == MISS ] + [C]
            maxGap = None
            for i in range(len(misspos)-1):
                gap = misspos[i+1] - misspos[i]
                if maxGap == None or gap > maxGap:
                    maxGap = gap
                    maxGapPos = misspos[i]+1, misspos[i+1]
            assert maxGap != None
            return maxGapPos

    def consistent(state):
        minl, maxl = shiprange(state)
        if minl + W > maxl:
            return False

        misspos = [-1] + [ i for i, v in enumerate(state) if v == MISS ] + [C]
        hit = find(HIT, state, 0)
        if hit == -1:
            mg = max(misspos[i+1] - misspos[i] for i in range(len(misspos) - 1))
            return W <= mg

        for i in range(len(misspos) - 1):
            if misspos[i] <= hit and hit < misspos[i+1]:
                return all(misspos[i] <= h and h < misspos[i+1] for h, v in enumerate(state) if v == HIT)
        assert False

    def opponent(state, playpos):
        #print "opponent", pprint(state), playpos
        assert state[playpos] == UNKNOWN
        s1 = state[:]
        s1[playpos] = MISS
        maxmoves1 = -1
        if consistent(s1):
            maxmoves1 = best(s1)

        s2 = state[:]
        s2[playpos] = HIT
        maxmoves2 = -1
        if consistent(s2):
            maxmoves2 = best(s2)

        return max(maxmoves1, maxmoves2)

    stateCache = dict()

    def best(state):
        ts = tuple(state)
        if stateCache.has_key(ts):
            return stateCache[ts]

        #print "best", pprint(state)

        # sunk?
        hits = sum(1 if s == HIT else 0 for s in state)
        if hits == W:
            stateCache[ts] = 0
            return 0

        # can I win?
        if False:
            minl, maxl = shiprange(state)

            if minl + W == maxl:
                need = 0
                for p in range(minl, maxl):
                    if state[p] == MISS:
                        print "inconsistent: ", pprint(state)
                        assert False

                    if state[p] != HIT:
                        need += 1
                print need, "more moves for ", pprint(state)
                stateCache[ts] = need
                return need

        bw = 9999
        for p in range(len(state)):
            if state[p] == UNKNOWN:
                bw = min(bw, 1 + opponent(state, p))

        stateCache[ts] = bw
        return bw

    moves = best([UNKNOWN] * C)
    print "Case #%d: %d" % (t, moves)
    if False:
        for k, v in sorted(stateCache.items()):
            print pprint(list(k)), v

