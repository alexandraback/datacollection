arr=    [[0,0,0,0,0],
        [0,1,2,3,4],
        [0,2,-1,4,-3],
        [0,3,-4,-1,2],
        [0,4,3,-2,-1]]
def con(s):
        if(s=='i'):
                return 2
        if(s=='j'):
                return 3
        if(s=='k'):
                return 4
        return s

def multiply(s,c):
        s=con(s)
        c=con(c)
        flag=False
        if(s<0):
                flag = not flag
                s=abs(s)
        if(c<0):
                flag = not flag
                c=abs(c)
        if(flag):
                return -arr[s][c]
        return arr[s][c]

T=input()
for t in xrange(1,T+1):
	L,X=map(int,raw_input().split())
	S=raw_input()
	m=1
	count=1
	print "Case #%d:"%t,
	flag=False
	for x in S:
		m=multiply(m,x)
	if(m==-1):
		flag=True
	if(X%2==0):
		if(m==-1):
			flag=False
		elif(m==1):
			flag=False
		else:
			if(X%4):		
				flag=True
	if(flag):
		if(X<=8):
			S=S*X
		else:
			S=S*8
		I=[]
		k=1
		flag_i=False
		flag_j=False
		for x in xrange(len(S)):
			k=multiply(k,S[x])
			I.append(k)
		for x in I:
			if(x==2 and not flag_i):
				flag_i=True
			if(x==4 and flag_i):
				flag_j=True
		if(flag_i and flag_j):
			print "YES"
		else:
			print "NO"
	else:
		print "NO"



	'''
	if(flag):
		flag_i=False
		flag_j=False
		flag_k=False
		I=[]
		k=1
		for x in S:
			k=multiply(k,x)
			I.append(k)
		for x in I:
			if(x==2 and not flag_i):
				flag_i=True
			if(x==4 and flag_i):
				flag_j=True
		if(flag_i and flag_j):	
			print "YES"
		elif(count==X):
			print "NO"
		else:
			count+=1
			for x in I:
				k=multiply(m,x)
				if(k==2 and not flag_i):
					flag_i=True
				if(k==4 and flag_i):
					flag_j=True
			if(flag_i and flag_j):	
				print "YES"
			elif(count==X):
				print "NO"
			else:
				count+=1
				m=multiply(m,m)
				for x in I:
					k=multiply(m,x)
					if(k==2 and not flag_i):
						flag_i=True
					if(k==4 and flag_i):
						flag_j=True
				if(flag_i and flag_j):
					print "YES"
				elif(count==X):
					print "NO"
				else:
					count+=1
					m=multiply(m,I[-1])
					for x in I:
						k=multiply(m,x)
						if(k==2 and not flag_i):
							flag_i=True
						if(k==4 and flag_i):
							flag_j=True
					if(flag_i and flag_j):
						print "YES"
					elif(count==X):
						print "NO"
					else:
						count+=1
						m=multiply(m,I[-1])
						for x in I:
							k=multiply(m,x)
							if(k==2 and not flag_i):
								flag_i=True
							if(k==4 and flag_i):
								flag_j=True
						if(flag_i and flag_j):
							print "YES"
						else:
							print "NO"
	else:
		print "NO"
	'''
