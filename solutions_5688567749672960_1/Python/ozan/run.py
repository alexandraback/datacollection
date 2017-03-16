def helper(N):
        if N <= 10:
                return N
        _ = str(N)
        l = len(_)
        half1 = _[:l/2]
        half2 = _[l/2:]
        n1 = int(half1[-1::-1])
        n2 = int(half2)
        if n2 == 0:
                return helper(N-1) + 1
        count = helper(10**(l-1))
        if n1 == 1:
                count += n2
        else:
                count += n1
                count += n2
        return count
	

	
def solve():
	N = int(raw_input())
	return helper(N)
		
	
	

T = int(raw_input())
for i in xrange(T):
	print 'Case #%d: %d' % (i+1, solve())

