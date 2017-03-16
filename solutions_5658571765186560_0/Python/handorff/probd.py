gabe = 'GABRIEL'
rick = 'RICHARD'

def solve(x, r, c):
    if r < c:
        tmp = r
        r = c
        c = tmp
    if x == 1:
        return gabe
    elif x == 2:
        if (r * c) % 2 == 0:
            return gabe
        else:
            return rick
    elif x == 3:
        if r != 3 and c != 3:
            return rick
        elif (r, c) == (3, 1):
            return rick
        else:
            return gabe
    elif x == 4:
        if (r * c) % 4 != 0:
            return rick
        elif (r, c) in [(4, 3), (4, 4)]:
            return gabe
        else:
            return rick
    else:
        assert 0, 'X not in [1, 4]'

t = int(raw_input())
test_cases = []

for i in xrange(t):
    x, r, c = map(int, raw_input().split(' '))
    test_cases.append((x, r, c))

for i in xrange(t):
    x, r, c = test_cases[i]
    print "Case #%d: %s" % (i + 1, solve(x, r, c))
