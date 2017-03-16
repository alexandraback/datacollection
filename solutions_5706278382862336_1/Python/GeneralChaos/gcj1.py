from math import ceil,log

def find_k(p,q):
	k  = 1
	while p*2**k < q:
		k += 1
	return k

def solve(p,q):
	k = find_k(p,q)
	res = k

	if k > 40:
		return -1

	p_new = p*2**k - q
	q_new = q*2**k
	
	while p_new >  0:
		p = p_new
		q = q_new

		k = find_k(p,q)
		
		if k > 40:
			return -1

		p_new = p*2**k - q
		q_new = q*2**k
	
	return res

T = int(raw_input())

for i in range(T):
	case = map(int, raw_input().split('/') )
	res = solve(case[0],case[1])
	if res < 0:
		print 'Case #%d: impossible' % (i+1)
	else:
		print 'Case #%d: %d' % (i + 1,  res)

