from template import * 

readFile('fractiles')

T = readInt()
for t in range(T):
	K = readInt()
	C = readInt()
	S = readInt()
	answer("Case #"+str(t+1)+":")
	if S*C<K:
		answerLn(" IMPOSSIBLE")
	else:
		l = range(K)
		while len(l)>0:
			r= l[:C]
			l=l[C:]
			i = 1
			p = K**(C-1)
			for a in r:
				i+=p*a
				p/=K
			answer(" "+str(i))
		answerLn("")