def approx_palin(le):
	s=str(le)
	if len(s)&1:
		odd=int(s[:(len(s)+1)/2])
		even=10**(len(str(odd))-1)-1
	else:
		even=int(s[:len(s)/2])
		odd=10**len(str(even))-1
	for i in xrange(1,odd+1):
		s=str(i)
		yield int(s+s[-2::-1])
	for i in xrange(1,even+1):
		s=str(i)
		yield int(s+s[::-1])
ssp=[]
for x in approx_palin(int(1+10**(14/2))):
	sq=str(x**2)
	if sq==sq[::-1]:
		ssp.append(x**2)
for t in xrange(1,1+int(raw_input())):
	a,b=map(int,raw_input().split())
	print"Case #%d:"%t,sum(a<=x<=b for x in ssp)
