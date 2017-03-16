import sys

cases = long(sys.stdin.readline())


def doit(values, E, R, N, current_time, current_energy, current_production):
    if current_time == N:
        return current_production
    maxx = 0
    for used_now in xrange(current_energy+1):
        if current_energy - used_now >= 0:
            maxx = max(maxx, doit(values, E, R, N, current_time + 1, min(current_energy + R - used_now, E), current_production + used_now * values[current_time]))
    return maxx

for case in xrange(cases):
    E, R, N = map(lambda x: int(x), sys.stdin.readline().split(' '))
    values = map(lambda x: int(x), sys.stdin.readline().split(' '))

    # look at every possible division of E energy between N activities
    # with slight overlap
    maxx = doit(values, E, R, N, 0, E, 0)

    print 'Case #'+str(case+1)+': '+str(maxx)
