T=int(raw_input())
def powerproduct(lst):
	if lst==[]:
		return [1]
	r=powerproduct(lst[:-1])
	return r+[i*lst[-1] for i in r]
for case in xrange(T):
	print 'Case #%d:'%(case+1)
	R,N,M,K=map(int,raw_input().split())
	digits=[[]]
	for i in xrange(3):
		digits=[j+[k,] for j in digits for k in xrange(2,M+1)]
	products=map(set,map(powerproduct,digits))
	#for i,j in zip(digits,products):
		#print i,j
	for i in xrange(R):
		ps=map(int,raw_input().split())
		for j in xrange(len(digits)):
			if all(k in products[j] for k in ps):
				print ''.join(map(str,digits[j]))
				break
		else:
			print '222'
