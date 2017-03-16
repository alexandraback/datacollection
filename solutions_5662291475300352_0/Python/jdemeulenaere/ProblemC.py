data = open("input/problemc.txt")
nb_cases = int(data.readline())

def encounter(h1,h2):
    p1 = float(h1[0])
    p2 = float(h2[0])
    s1 = float(h1[1])
    s2 = float(h2[1])

    if s1 < s2:
        return encounter(h2,h1)

    rem_s1 = 360.0 - p1
    rem_s2 = 360.0 - p2

    time_s1 = rem_s1 * s1 / 360.0

    dist_s2 = time_s1 / s2
    if dist_s2 > (1.0 + rem_s2 / 360.0):
        print 1
    else:
        print 0






for z in xrange(nb_cases):
    print "Case #%d:" % (z + 1),
    n = int(data.readline())
    groups = [[int(x) for x in data.readline().split(" ")] for _ in xrange(n)]
    h1 = [] # [pos, speed]
    h2 = []
    if len(groups) == 1:
        g = groups[0]
        h1 = [g[0], g[2]]
        h2 = [g[0], g[2] + 1]
    else:
        g = groups[0]
        h1 = [g[0], g[2]]
        g = groups[1]
        h2 = [g[0], g[2]]

    if h1[1] == h2[1]:
        print 0
    else:
        encounter(h1,h2)


