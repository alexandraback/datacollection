def solve():
    s = raw_input()
    count = 0
    for i in xrange(len(s) - 1):
        if s[i] != s[i + 1]:
            count += 1
    if s[-1] == '-':
        count += 1
    return count

T = int(raw_input())
for i in range(T):
    print 'Case #%d:' % (i + 1), solve()
