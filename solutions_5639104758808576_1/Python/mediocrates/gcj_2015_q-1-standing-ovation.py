g = open('A-large.in', 'r+b')
T = int(g.readline().strip())
for t in range(1,T+1):
    S_max, data = g.readline().strip().split()
    S_max = int(S_max)
    retval = 0
    total = 0
    for i in range(len(data)):
        total += int(data[i])
        if total < i+1:
            total += 1
            retval += 1
    print 'Case #%d: %d' % (t, retval)
g.close()