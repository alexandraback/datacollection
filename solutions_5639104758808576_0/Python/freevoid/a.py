import sys

def solve(smax, audience):
    friends = 0
    standed = 0
    for level, n in enumerate(audience):
        friends += max(0, level - friends - standed)
        standed += n
    return friends


def read_ints():
    return map(int, sys.stdin.readline().split(' '))

t, = read_ints()
for i in range(t):
    smax, audience = sys.stdin.readline().strip().split(' ')
    audience = map(int, audience)
    print 'Case #%d: %d' % (i + 1, solve(smax, audience))
