from sys import*

setrecursionlimit(10000)

def REV(n):
	m=0
	while n>0:
		m*=10
		m+=(n%10)
		n//=10
	return m

def REK(table,nu,h):
	#print(table)
	if len(nu)==0:
		return
	da=[]
	for n in nu:
		if not n in table and n<=1000000:
			da.append(n+1)
			da.append(REV(n))
		if n<=1000000:
			table.setdefault(n,h)
	REK(table,da,h+1)
	

f=open("A-small-attempt0.in","r")
g=open("OUT.txt","w")
T=int(f.readline())

table={}

REK(table,[1],1)

for i in range(T):
	N=int(f.readline())
	if N in table:
		g.write("Case #{}: {}\n".format(i+1,table[N]))

f.close()
g.close()

