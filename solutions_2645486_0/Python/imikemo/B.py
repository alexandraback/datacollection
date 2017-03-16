import sys

f = open(sys.argv[1])

T = int(f.readline())

for tc in range(T):
    E, R, ac = [int(v) for v in f.readline().split()]
    a = [int(v) for v in f.readline().split()]
    s = sorted(a, reverse=True)
    total = E*s[0]
    for si in s[1:]:
        total += si*R
    print 'Case #%s: %s' % (tc+1, total)
