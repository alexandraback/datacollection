import sys
from string import lowercase as lc
T = int(raw_input())

M = 1000000007

def solve(C):
    print "Case #" + str(C+1) + ":",

    factor = 1
    n = int(raw_input())
    inp = raw_input().strip().split()
    t = []
    for s in inp:
        ns = ''
        for i in xrange(len(s)):
            if i == 0: ns += s[i]
            elif s[i] != s[i-1]: ns += s[i]
        t.append(ns)

    grp = 0
    st = {}
    ed = {}
    for s in t:
        if len(s) == 1: continue
        if s[0] in st: return -1
        if s[-1] in ed: return -1
        if s[0] == s[-1]: return -1
        st[s[0]] = s
        ed[s[-1]] = s

    mid = ''.join(s[1:-1] for s in t)
    for c in lc:
        if (c in st or c in ed) and mid.count(c): return -1
        if mid.count(c) > 1: return -1

    #sys.stderr.write("ASONETHO\n")
    onel = {}
    seen = set()
    for s in t:
        #sys.stderr.write(s+"\n")
        
        if len(s) == 1:
            if s not in onel:
                onel[s] = 1
                if s not in st and s not in ed: grp += 1
            else:
                onel[s] += 1
                factor *= onel[s]
                factor %= M
            continue

        # not 1 char
        if s in seen: continue
        seen.add(s)
        grp += 1

        # go back
        at = s
        while at[0] in ed:
            at = ed[at[0]]
            if at in seen: return -1
            seen.add(at)
        
        # forth
        at = s
        while at[-1] in st:
            at = st[at[-1]]
            seen.add(at)

    for i in xrange(1, grp + 1):
        factor *= i
        factor %= M
    print factor
    return 0

for C in xrange(T):
    if solve(C) == -1: print 0
    #sys.stderr.write(str(C) + "\n")
