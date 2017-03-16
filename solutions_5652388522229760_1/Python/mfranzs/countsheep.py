from template import * 

readFile('countsheep')

T = readInt()
for t in range(T):
	print "Case #"+str(t+1)+":",
	N = readInt()
	i = N
	if N == 0:
		print "INSOMNIA"
	else:
		seenDigits = {}
		seen = 0
		while seen < 10:
			for c in str(i):
				if not c in  seenDigits:
					seenDigits[c]= True
					seen +=1
			i+=N
		i-=N
		print i

