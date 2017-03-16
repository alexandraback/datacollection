vowels='aeiou'
consonants='bcdfghjklmnpqrstvwxyz'
def nvalue(name,n):
	ans=0
	consecutive=[]
	for i in range(len(name)):
		if i<=len(name)-n:
			t=name[i:i+n]
			for v in vowels:
				if v in t:
					break
			else:
				consecutive.append(i)
	for i in range(len(name)-n+1):
		for j in range(i+n,len(name)+1):
			for c in consecutive:
				if c>=i and c+n<=j:
					ans+=1
					break
	return ans
lines=[i.replace('\n','') for i in open('A-small-attempt0.in','r').readlines()[1:]]
out=open('output.txt','w')
for i in range(len(lines)):
	out.write(('Case #{0}: '+str(nvalue(lines[i].split()[0],int(lines[i].split()[1])))+'\n').format(i+1))