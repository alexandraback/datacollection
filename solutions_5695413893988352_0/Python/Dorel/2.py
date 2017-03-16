from itertools import product

dig = ['0','1','2','3','4','5','6','7','8','9']

def decode(a, b):
	diff = 9999
	ans_a, ans_b=a,b
	n,m=a.count('?'), b.count('?')
	for x in product(dig,repeat=n):
		for y in product(dig,repeat=m):
			pa, pb = a, b
			for z in x : pa = pa.replace('?',z,1)
			for z in y : pb = pb.replace('?',z,1)
			if abs(int(pa)-int(pb))<diff :
				diff=abs(int(pa)-int(pb))
				ans_a, ans_b= pa, pb
	return ans_a, ans_b 
	
T=int(raw_input())
for test in xrange(1,T+1):
	a,b = raw_input().strip().split()
	ans_a, ans_b = decode(a,b)
	print "Case #%d:"%test,ans_a,ans_b	 
