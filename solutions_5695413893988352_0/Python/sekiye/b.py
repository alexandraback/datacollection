import itertools

def match(s, n):
    x = str(n)
    while len(x) < len(s):
        x = '0' + x
    for i in xrange(len(s)):
        if not (s[i] == '?' or s[i] == x[i]):
           return False
    return True

def solve():
    C, J = raw_input().split()
    l = len(C)
    min_ = (1000, 0, 0)
    for i in xrange(10 ** l):
        if not match(C, i):
            continue
        for j in xrange(10 ** l):
            if not match(J, j):
                continue
            if min_[0] > abs(i - j):
                min_ = (abs(i - j), i, j)
    C, J = str(min_[1]), str(min_[2])
    while len(C) < l:
        C = '0' + C
    while len(J) < l:
        J = '0' + J
    if l != len(C) or l != len(J):
        print 'hogeeee'
    return C + ' ' + J

T = int(raw_input())
for i in range(T):
    print 'Case #%d:' % (i + 1), solve()
