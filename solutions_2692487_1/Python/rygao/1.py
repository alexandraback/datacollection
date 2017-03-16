def add_motes(A, m):
    adds = []
    for i in xrange(len(m)):
        if A <= m[0]:
            if A <= 1:
                return len(m)
            else:
                while A <= m[0]:
                    A += A-1
                    adds.append(len(m))
        A += m[0]
        del m[0]

    adds.append(0)
    return min([i+j for i,j in zip(adds, range(len(adds)))])


f = open('A-large.in', 'r')
T = f.readline().strip()
T = int(T)

g = open('output-large.txt', 'w')

for i in xrange(T):
    A, N = [int(j) for j in f.readline().split()]
    
    m = [int(j) for j in f.readline().split()]
    assert(len(m) == N)
    m.sort()
    
    g.write('Case #%d: %d\n' % (i+1, add_motes(A, m)))


f.close()
g.close()
