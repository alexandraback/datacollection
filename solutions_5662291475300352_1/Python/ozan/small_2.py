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
        h = map(int, h.split())
        for j in xrange(h[1]):
            hikers.append(Hiker(h[0], h[2]+j))
    hikers = sorted(hikers)
    c = map(lambda i:sorted(map(lambda x:x.c(i), hikers)), xrange(1,len(hikers)+1))
    c1 = sorted(map(lambda x:x.c(1), hikers))[-1::-1]
    result = len(hikers)
    for i, x in enumerate(c1):
        count = -1
        for cs in c:
            for y in cs:
                if y <= x:
                    count += 1
                else:
                    break
        if result > count:
            result = count
    return result
    
    
		
	
	

T = int(raw_input())
for i in xrange(T):
	print 'Case #%d: %d' % (i+1, solve())
