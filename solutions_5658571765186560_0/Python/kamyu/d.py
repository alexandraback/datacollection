def solve():
    s = map(int, raw_input().split())
    if s[0] == 1:
        return "GABRIEL"

    if s[0] >= 7:
        return "RICHARD"

    if s[0] > s[1] and s[0] > s[2]:
        return "RICHARD"
    
    if s[1] % s[0] != 0 and s[2] % s[0] != 0:
        return "RICHARD"

    if s[1] < s[0] - 1 or s[2] < s[0] - 1:
        return "RICHARD"

    return "GABRIEL"

T = input()
for i in xrange(T):
    print 'Case #%d: %s' % (i + 1, solve())
