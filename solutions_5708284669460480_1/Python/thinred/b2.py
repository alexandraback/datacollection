
from itertools import product
from collections import defaultdict
import sys

def overlaps(s):
    for i in xrange(1, len(s)):
        if s[:-i] == s[i:]:
            return i
    return len(s)

def fits(s, count):
    o = overlaps(s)
    f = len(s)
    c = 0
    while f <= count:
        c += 1
        f += o
    return c

def howmany(a, s):
    c = 0
    for i in xrange(len(s) - len(a) + 1):
        if a == s[i:i+len(a)]:
            c += 1
    return c

def solve(s, kb, tt):
    if not (set(tt) <= set(kb)):
        return 0.0
    p = 0.0
    bananas = 0
    c = 0
    M = fits(tt, s) # maximum number of bananas
    # print M
    if M == 0:
        return 0.0
    for seq in product(kb, repeat = s):
        seq = ''.join(seq)
        # print seq, howmany(tt, seq)
        c += 1
        bananas += howmany(tt, seq)
    return float(M) - float(bananas) / float(c)


def get_probs(kb):
    h = defaultdict(int)
    for c in kb:
        h[c] += 1
    for c in h.keys():
        h[c] = float(h[c]) / len(kb)
    return h

def is_prefix(a, s):
    return s[:len(a)] == a


# cache = {}
def find_max_state(tt, s):
    # key = (tt, s)
    # if key in cache:
    #    return cache[key]
    # looks for max suffix of s that matches prefix of tt
    best = 0
    for i in xrange(1, len(s) + 1):
        if s[-i:] == tt[:i]:
            best = i
    # cache[key] = best
    return best

def solve2(s, kb, tt):
    if not (set(tt) <= set(kb)):
        return 0.0
    ps = get_probs(kb)
    t = len(tt) + 1
    state = [ 0.0 ] * t
    state[0] = 1.0
    bananas = 0.0
    for i in xrange(s):
        # print state
        nstate = [ 0.0 ] * t
        for st in xrange(t):
            cmatch = tt[:st]
            for c in ps:
                # for each state and next key
                nmatch = cmatch + c
                x = find_max_state(tt, nmatch)
                nstate[x] += state[st] * ps[c]
        state = nstate
        bananas += state[t - 1] # prob. that full match is here
    return fits(tt, s) - bananas

if __name__ == '__main__':

    lines = sys.stdin.readlines()
    T = int(lines[0].strip())

    for i in xrange(T):
        k, l, s = map(int, lines[3*i+1].split())
        kb = lines[3*i+2].strip()
        tt = lines[3*i+3].strip()
        assert len(kb) == k
        assert len(tt) == l
        if s <= 7 and False:  # TODO
            h = solve(s, kb, tt)
        else:
            h = solve2(s, kb, tt)
        print "Case #%d: %.10f" % (i+1, h)
