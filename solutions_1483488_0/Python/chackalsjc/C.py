# Google Code Jam 2012 Qualification Round
# C

if __name__ == '__main__':
    T = int(raw_input())
    for i in xrange(T):
        (A, B) = raw_input().split()
        (a, b) = (int(A), int(B))
        y = 0
        for j in xrange(b - a):
            n = a + j
            N = str(n)
            mem = []
            for k in xrange(len(N) - 1):
                m = int(N[-(k+1):] + N[0:-(k+1)])
                if m <= b and m > n and m not in mem:
                    mem.append(m)
                    y += 1
        
        print 'Case #%d: %d' % (i+1, y)