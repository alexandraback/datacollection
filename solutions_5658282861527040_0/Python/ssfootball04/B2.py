import fileinput

f=fileinput.input()
T=int(f.readline())
g=open('output','w')

def solve(A,B,K):
	s=0
	for i in range(A):
		for j in range(B):
			if(i&j<K):
				s=s+1
	return str(s)

for l in range(T):
	line=f.readline()
	j=0
	while(line[j]!=' '):
		j=j+1
	A=int(line[:j])
	p=j+1
	while(line[p]!=' '):
		p=p+1
	B=int(line[j+1:p])
	K=int(line[p+1:])
	ans=solve(A,B,K)
	g.write( 'Case #'+str(l+1)+': '+ans+"\n")
