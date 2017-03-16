from fractions import gcd

def find(no):
	while no>1:
		no /= 2
	if no==1:
		return True
	else:
		return False
		
def ans(no,level):
	if no < 0.5:
		return ans(no*2,level+1)
	else:
		return level


t = int(raw_input())
for tc in xrange(t):
	pq = raw_input().split("/")
	p = int(pq[0])
	q = int(pq[1])
	gc = gcd(p,q)
		
	p = float(p)/gc
	q = float(q)/gc
		
	if find(q):
		print "Case #"+str(tc+1)+": "+str(ans(p/q,1))
	else:
		print "Case #"+str(tc+1)+": impossible"
