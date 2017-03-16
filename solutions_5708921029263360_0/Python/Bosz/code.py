import numpy as np

def perm(j,p,s,J,P,S,K):
	global count
	if(mem1[j][p][s]<1):
		if(mem2[0][j][p]<K and mem2[1][j][s]<K and mem2[2][p][s]<K):
			#print j,p,s
			mem1[j][p][s]=mem1[j][p][s]+1
			mem2[0][j][p]=mem2[0][j][p]+1
			mem2[1][j][s]=mem2[1][j][s]+1
			mem2[2][p][s]=mem2[2][p][s]+1
			count +=1
			ans.append([j,p,s])
	if(j==J and p==P and s==S):
		return
	if(j<J): perm(j+1,p,s,J,P,S,K)
	if(p<P): perm(j,p+1,s,J,P,S,K)
	if(s<S): perm(j,p,s+1,J,P,S,K)
		

T =int(input())
mem1=[]
mem2=[]
count=0
ans=[]
for case in range(1,T+1):
	J,P,S,K = [int(s) for s in raw_input().split(' ')]
	mem1=np.zeros((J+1,P+1,S+1))
	mem2=np.zeros((3,P+1,S+1))
	count=0
	ans=[]
	perm(1,1,1,J,P,S,K)
	#print mem1
	print 'Case #{}: {}'.format(case,count)
	for a in ans:
		st = ''
		for aa in a:
			st+=str(aa)+' '
		print st.strip()
	