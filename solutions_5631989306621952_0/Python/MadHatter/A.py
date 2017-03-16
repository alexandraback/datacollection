__author__ = 'dkopiychenko'

def solve(s):
    r = s[0]
    c = s[0]
    for x in s[1:]:
        if x >= c:
            r = x + r
            c = x
        else: r = r + x
    return r

t = int(raw_input())
for i in xrange(t):
    s = raw_input().strip()
    print 'Case #' + str(i+1) + ': ' + str(solve(s))
