goodnumbers=[]
for i in xrange(1,10000001):
	t=str(i)
	if t!=t[::-1]:
		continue
	s=str(i*i)
	if s==s[::-1]:
		goodnumbers.append(i*i)
		#print i,s
T=int(raw_input())
for case in xrange(T):
	A,B=map(int,raw_input().split())
	ret=len([i for i in goodnumbers if i>=A and i<=B])
	print 'Case #%d:'%(case+1),ret
