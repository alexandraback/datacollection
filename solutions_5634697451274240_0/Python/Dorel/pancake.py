f=open("input")
NR=int(f.readline().strip())

for test in xrange(1,NR+1):
	s=f.readline().strip()
	if (s=='-') : print("Case #%d: 1"%test)
	elif (s=='+') : print("Case #%d: 0"%test)
	else :
		signs=1
		for i in xrange(len(s)-1) : 
			if (s[i:i+2] in ['-+','+-']) : signs+=1
		if (s[0]=='-') : print("Case #%d: %d"%(test, signs-1+(signs&1)))
		else           : print("Case #%d: %d"%(test, signs-1 + (signs+1&1)))

