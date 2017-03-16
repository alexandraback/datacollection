from template import * 

readFile('r22')

T = readInt()
for t in range(T):		
	cur = None
	N = readInt()
	s = {}
	for i in range(2*N-1):
		for k in range(N):
			z = readInt()
			if not z in s:
				s[z]=0
			s[z]+=1
	o = []
	for i in s:
		if s[i]%2==1:
			o.append(i)
	o.sort()
	ou=""
	answer("Case #"+str(t+1)+":")
	for i in o:
		answer(" "+str(i))
	answerLn(ou)
