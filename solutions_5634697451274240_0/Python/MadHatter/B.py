__author__ = 'dkopiychenko'

def solve(s):
    n = 0
    c = s[0]
    for i in xrange(1,len(s)):
        cc = s[i]
        if cc != c: n += 1
        c = cc
    if s[-1] == '-': n += 1
    return n

t = int(raw_input())
for i in xrange(t):
    s = raw_input()
    print 'Case #' + str(i+1) + ': ' + str(solve(s))