from sys import*

def SOLVE(N,soldiers):
	count={}
	for l in soldiers:
		for p in l:
			count.setdefault(p,0)
			count[p]+=1
	
	li=[]
	for p in count:
		if count[p]%2==1:
			li.append(p)
	
	if len(li)<N:
		a=0 #####
	
	li.sort()
	return li


def SOLVE2(N,soldiers):
	solution=[[0 for i in range(N)] for i in range(N)]
	
	for i in range(N):
		cur=min(soldiers)
		for j in range(len(soldiers)):
			if soldiers[j]==cur:
				del(soldiers[j])
				break
		for j in range(i,N):
			a=0#solution[]
	
	print(solution)
		

f=open("B-large.in","r")
g=open("google.out","w+")
T=int(f.readline())

for i in range(T):
	N=int(f.readline())
	soldiers=[[int(j) for j in f.readline().split()] for k in range(2*N-1)]
	ans=SOLVE(N,soldiers)
	g.write("Case #{}: ".format(i+1))
	for j in ans:
		g.write("{} ".format(j))
	g.write("\n")

f.close()
