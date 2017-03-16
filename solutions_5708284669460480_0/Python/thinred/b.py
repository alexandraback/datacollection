
from itertools import product
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

if __name__ == '__main__':

    lines = sys.stdin.readlines()
    T = int(lines[0].strip())
    
    for i in xrange(T):
        k, l, s = map(int, lines[3*i+1].split())
        kb = lines[3*i+2].strip()
        tt = lines[3*i+3].strip()
        assert len(kb) == k
        assert len(tt) == l
        if s <= 7:
            h = solve(s, kb, tt)
        else:
            rerror
        print "Case #%d: %.10f" % (i+1, h)
