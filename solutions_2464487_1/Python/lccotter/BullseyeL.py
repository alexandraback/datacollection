
def calc(x,r):
	return x*(2*r-3) + 2*x*(x+1)

def main():	
	global pl
	T=input()
	for c in xrange(T):
		an=0
		r, t = map(int, raw_input().split())
		sn, en = 0, 10**10
		pre=0
		while sn <= en:
			an=sn+(en-sn)/2
			need=calc(an,r)
			if need <= t:
				sn=an+1
				pre=an
			else :
				en=an-1
		print "Case #%d: %d" % (c+1, pre)

if __name__ == "__main__":
	main()
	#print calc(1,1)
	#print calc(2,1)
	#print calc(3,1)