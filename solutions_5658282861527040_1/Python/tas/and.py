
import sys

def to_binary(x,n):
	xb=[]
	for i in range(n):
		xb.append((x%2)==1)
		x = x/2
	return xb

def match(x,y):
	return (x==None) or (x==y)

#a,b,k are length-n lists of True,False,None
#each list specifies a pattern that can be matched
#i.e. True and False are fixed, but None can take either value
#we want to count of True-False vectors aa and bb matching a and b
#such that aa and bb matches k
def suffix_count(a,b,k,n):
	ans = 1
	for i in range(n):
		poss=0
		if match(a[i],True) and match(b[i],True) and match(k[i],True): poss += 1
		if match(k[i],False):
			if match(a[i],True) and match(b[i],False): poss += 1
			if match(a[i],False) and match(b[i],True): poss += 1
			if match(a[i],False) and match(b[i],False): poss += 1
		ans *= poss
	return ans

#a is a length-n list of True,False
#a represents an integer
#yield a list of suffixes such that
#x<a is equivalent to x being matched by one suffix
def list_suffixes(a,n):
	for i in range(n):
		if a[i]:
			suff=a[:]
			suff[i]=False
			for j in range(i):
				suff[j]=None
			yield suff

t = int(sys.stdin.readline())
for c in range(t):
	abk=sys.stdin.readline().split()
	assert len(abk)==3
	a = int(abk[0])
	b = int(abk[1])
	k = int(abk[2])
	assert a>0
	assert b>0
	assert k>0
	n = 1
	while 2**n <= a or 2**n <= b or 2**n <= k: n+=1
	aa = to_binary(a,n)
	bb = to_binary(b,n)
	kk = to_binary(k,n)

	##How many suffixes?
	#num_suffs=0
	#for suff in list_suffixes(aa,n): num_suffs+=1
	#print num_suffs

	count = 0
	for asuff in list_suffixes(aa,n):
		for bsuff in list_suffixes(bb,n):
			for ksuff in list_suffixes(kk,n):
				count += suffix_count(asuff,bsuff,ksuff,n)
	print "Case #"+str(c+1)+": "+str(count)
