ans = "Case #{}: {}"
m = 1000000007

def fact(n,m):
	rt = 1
	for i in range(1,n+1):
		rt = (rt*i)%m
	return rt

def isOkay(st):
	if(st==''):
		return True
	d = [0]*26
	d[ord(st[0])-97] = 1
	for i in range(1,len(st)):
		if(st[i]!=st[i-1]):
			if(d[ord(st[i])-97] == 1):
				return False
			d[ord(st[i])-97] = 1
	return True

def f(A):
	if(not all(map(isOkay,A))):
		return 0
	rt = []
	s = [[] for i in range(26)]
	e = [[] for i in range(26)]
	se = [[] for i in range(26)]
	for i in range(len(A)):
		if(A[i][0] != A[i][-1]): s[ord(A[i][0])-97].append(i); e[ord(A[i][-1])-97].append(i)
		else: se[ord(A[i][0])-97].append(i)
	for i in range(26):
		if(len(s[i])>1 or len(e[i])>1):
			return 0
	rt = [1]*len(A)
	for i in range(26):
		if(len(se[i]) > 0):
			for j in range(1,len(se[i])):
				A[se[i][0]] += A[se[i][j]] 
				A[se[i][j]] = ''
			rt[se[i][0]] = fact(len(se[i]),m)
			se[i] = [se[i][0]]
	for i in range(26):
		if(len(e[i]) > 0 and len(se[i]) > 0):
			A[e[i][0]] += A[se[i][0]]
			A[se[i][0]] = ''
			rt[e[i][0]] *= rt[se[i][0]]
			rt[se[i][0]] = 1
		if(len(s[i]) > 0 and len(e[i]) > 0):
			fh = e[i][0]
			sh = s[i][0]
			A[fh] += A[sh]
			A[sh] = ''
			rt[fh] *= rt[sh]
			rt[sh] = 1
			del s[i][0]
			del e[i][0]
			if(A[fh]==''):
				return 0
			e[ord(A[fh][-1])-97] = [fh]
	if(not isOkay(''.join(A))):
		return 0
	k = fact(len([i for i in A if i!='']),m)
	for i in rt:
		k*=i
	return k

def takeInp():
	for t in range(int(input())):
		n = int(input())
		print(ans.format(t+1,f(input().split())))

takeInp()