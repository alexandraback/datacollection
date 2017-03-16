g = open('A-small-attempt0.in', 'r+b')
T = int(g.readline().strip())
for t in range(1,T+1):
    S_max, data = g.readline().strip().split()
    S_max = int(S_max)
    retval = 0
    total = 0
    for i in range(len(data)):
        total += int(data[i])
        if total < i+1:
            num_to_add = (i+1) - total
            total += num_to_add
            retval += num_to_add
            # total += 1
            # retval += 1
    print 'Case #%d: %d' % (t, retval)
g.close()