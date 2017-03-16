t = int(raw_input())

def test(T):
	s = list(raw_input())+['+']
	print 'Case #%d: %d'%(T,sum(map(lambda(a,b):a!=b,zip(s,s[1:]))))
	

for i in range(1,t+1):
	test(i)
