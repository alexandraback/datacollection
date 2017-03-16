class Hiker:
    def __init__(self, p, t):
        self.s = 360./t
        self.p = p
    def c(self, n):
        return (360*n-self.p)/self.s

    def __lt__(self, rhs):
        if self.p == rhs.p:
            return self.s < rhs.s
        return self.p < rhs.p

def solve():
    N = int(raw_input())
    hikers = []
    for i in xrange(N):
        h = raw_input()
        hikers.append(map(int, h.split()))
    h1 = None
    h2 = None
    if N == 1:
        if hikers[0][1] == 1:
            return 0
        else:
            h1 = Hiker(hikers[0][0], hikers[0][2])
            h2 = Hiker(hikers[0][0], hikers[0][2]+1)
    else:
        h1 = Hiker(hikers[0][0], hikers[0][2])
        h2 = Hiker(hikers[1][0], hikers[1][2])
    x = h1 if h1 < h2 else h2
    y = h2 if h1 < h2 else h1
    if x.c(1) < y.c(2) and y.c(1) < x.c(2):
        return 0
    return 1
    
		
	
	

T = int(raw_input())
for i in xrange(T):
	print 'Case #%d: %d' % (i+1, solve())
