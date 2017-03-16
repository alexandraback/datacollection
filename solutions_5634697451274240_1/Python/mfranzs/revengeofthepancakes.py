from template import * 

readFile('revengeofthepancakes')

T = readInt()
for t in range(T):
	s = readLn()
	cur = None
	swaps = 0
	for c in s:
		if cur is None:
			cur = c
		else:
			if not cur == c:
				swaps +=1 
				cur = c
	if cur == '-':
		swaps +=1
	answerLn("Case #"+str(t+1)+": "+str(swaps))



