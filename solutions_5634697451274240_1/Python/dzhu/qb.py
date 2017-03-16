import sys

def calc(s):
    n = 0
    for i in xrange(1, len(s)):
        if s[i] != s[i-1]:
            n += 1
    n += s[-1] == 0
    return n

T = int(sys.stdin.readline())
for i in xrange(T):
    s = [c == '+' for c in sys.stdin.readline().strip()]
    print 'Case #%d: %d' % (i + 1, calc(s))
