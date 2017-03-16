"""
def choose(tr, s):
    if len(s) == 0:
        return 1
    rv = 0
    starts_with = []
    ends_with = []
    for t in s:
        if t[0] == tr[-1]:
            starts_with.append(t)
        if t[-1] == tr[0]:
            ends_with.append(t)
        
        nunusable = set(unusable)
        if last != None and s[i][0] != last:
            nunusable |= set(last)
        check = False
        for j in xrange(len(s[i])):
            if s[i][j] in nunusable:
                check = True
                break
            if j < len(s[i])-1 and s[i][j] != s[i][j + 1]:
                nunusable |= set(s[i][j])
                
        if check:
            continue
        rv += choose(s[:i] + s[i+1:], s[i][-1], nunusable)
    return rv
"""

def factorial(n):
    rv = 1
    for i in xrange(2, n + 1):
        rv *= i
    return rv

def check(s, m):
    bla = set(m.keys())
    partial = len(bla)
    for t in s.values():
        par = set(t)
        if len(par) != len(t):
            return False
        partial += len(par)
        bla |= par
    return len(bla) == partial

def process(st):
    rv = ""
    for c in st:
        if len(rv) > 0 and rv[-1] == c:
            continue
        rv += c
    return rv

def process_game():
    N = int(raw_input())
    s = raw_input().split()
    d_start = {}
    d_end = {}
    d_middle = {}
    for t in s:
        if t[0] == t[-1]:
            if len(set(t)) != 1:
                print 0
                return
            if t[0] not in d_middle:
                d_middle[t[0]] = 0
            d_middle[t[0]] += 1
            continue
        if t[0] in d_start:
            print 0
            return
        d_start[t[0]] = process(t)
        if t[-1] in d_end:
            print 0
            return
        d_end[t[-1]] = process(t)
    
    rv = 1
    for k, v in d_middle.iteritems():
        rv *= factorial(v)
    for k in d_start.keys():
        if k in d_middle:
            del d_middle[k]
        if k in d_end:
            nt = process(d_end[k] + d_start[k])
            del d_start[k]
            del d_end[k]
            d_start[nt[0]] = nt
            d_end[nt[-1]] = nt

    for k in d_end.keys():
        if k in d_middle:
            del d_middle[k]
    assert sorted(d_start.values()) == sorted(d_end.values())
    if not check(d_start, d_middle):
        print 0
        return
    print rv * factorial(len(d_start) + len(d_middle))

for i in xrange(1, int(raw_input()) + 1):
    print "Case #%d:" % (i),
    process_game()
