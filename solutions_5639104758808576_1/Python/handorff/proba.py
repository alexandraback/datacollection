def solve(s_max, s):
    ret = 0
    standing = 0
    for i in xrange(s_max + 1):
        if standing < i:
            ret += i - standing
            standing = i
        standing += s[i]
    return ret



t = int(raw_input())
test_cases = []

for i in xrange(t):
    s_max, inpt = raw_input().split(' ')
    s_max = int(s_max)
    s = []
    for j in xrange(s_max + 1):
        s.append(int(inpt[j]))
    test_cases.append((s_max, s))

for i in xrange(t):
    s_max, s = test_cases[i]
    print "Case #%d: %d" % (i + 1, solve(s_max, s))
