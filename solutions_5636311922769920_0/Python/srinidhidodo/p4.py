import itertools

def stringit(l):
	r=[]
	for i in l:
		x=''.join(i)
		r+=[x]
	return r

def complexify(l,c,k):
	r=l
	temp=[]
	for i in l:
		#print(i)
		t=i
		for curr in range(1,c):
			f=''
			for x in t:
				f=f+i if x=='L' else f+'G'*k
				#print(x,' ',f)
			t=f
		temp.append(t)
	r=temp if c>1 else r
	return r

def gentrues(l):
	t=[]
	for i in l:
		if 'G' in i:
			t.append(True)
		else:
			t.append(False)
	return t

def merge(l1,l2):
	l=[]
	#print('l1 ',l1,' l2 ',l2)
	for i in range(len(l1)):
		#print(i)
		if l1[i] or l2[i]:
			l.append(True)
		else:
			l.append(False)
	#print('l ',l)
	return l

def match(l,trues):
	res=[]
	for i in range(len(l)):
		if l[i]==trues[i]:
			res.append(True)
		else:
			res.append(False)
	return res

def constructtrus(l):
	ret=[]
	for i in range(thepower):
		ret.append([])
	for i in range(thepower):
		for j in range(perms):
			#print('j ',j,' i ',i)
			if l[j][i]=='G':
				ret[i]+=[True]
			else:
				ret[i]+=[False]
	return ret
	#print(ret,' ',thepower)
	
def find(curr,s,i):
	temp=[]
	for j in range(i+1,thepower):
		temp=merge(curr,truthtable[j])
		if all(match(temp,trues)):
			return [j]
		elif s==1:
			return []
		else:
			x=find(temp,s-1,j)
			if x!=[]:
				return x+[j]

n=int(input(''))
count=1
for i in range(n):
	s=input('')
	k=int(s[:s.index(' ')])
	s=s[s.index(' ')+1:]
	c=int(s[:s.index(' ')])
	s=s[s.index(' ')+1:]
	s=int(s)
	if s==1 and k>1:
		print('Case #{}: IMPOSSIBLE'.format(str(count)))
		count+=1
	elif k==s:
		r=list(range(1,k+1))
		f=''
		for i in r:
			f+=str(i)+' '
		print('Case #{}: {}'.format(str(count),str(f)))
		count+=1
	else:
		r=[]
		if k>20:
			k=20
		perms=2
		thepower=1
		if c>1:
			for i in range(k-1):
				perms*=2
		for i in range(c):
			thepower*=k
		#print('thepower ',thepower,' perms ',perms)
		poss=list(itertools.product('LG',repeat=k))
		poss=stringit(poss)
		l=complexify(poss,c,k)
		trues=gentrues(poss)
		#print(poss,' ',l,' ',trues)
		truthtable=constructtrus(l)
		#print('tt ',truthtable)
		r=find([False]*perms,s,-1)
		r=[i+1 for i in r]
		f=''
		for i in r:
			f+=str(i)+' '
		print('Case #{}: {}'.format(str(count),str(f)))
		count+=1
		#print('tt ',len(truthtable))
		#print(poss,' ',l,' ',trues)
	
