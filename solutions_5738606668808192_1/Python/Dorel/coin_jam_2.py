from random import choice  

f=open("input")
T=int(f.readline().strip())

for test in xrange(1,T+1):
	N,J = [ int(x) for x in f.readline().strip().split()]
	print("Case #%d:"%test)
	samples=set()
	while (len(samples)<J):
		samples.add('1' + ''.join([ choice(['0','1']) for x in xrange(N/2-2)]) + '1')
	for x in samples :
		print x+x, 1+2**(N/2), 1+3**(N/2),1+4**(N/2),1+5**(N/2),1+6**(N/2),1+7**(N/2),1+8**(N/2),1+9**(N/2),1+10**(N/2) 
