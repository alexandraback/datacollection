from template import * 

readFile('r21')

T = readInt()
for t in range(T):		
	cur = None
	l = readLn()
	o = None
	for c in l:
		
		if o == None:
			o = c
		else:
			if c>=o[0]:
				o=c+o
			else:
				o+=c

	answerLn("Case #"+str(t+1)+": "+o)

