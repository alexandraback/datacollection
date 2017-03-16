from sys import stdin

def each_case(s):
    maneuver = 1
    last_p = s[0]
    for pancake in s[1:]:
        if last_p != pancake:
            last_p = pancake
            maneuver += 1
    if s[-1] == '+':
        maneuver -= 1
    return maneuver

T = int(stdin.readline())
for t in xrange(1,T+1):
    print 'Case #{}: {}'.format(t, each_case(stdin.readline().strip()))
