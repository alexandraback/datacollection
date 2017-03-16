from __future__ import print_function

def reverse(N):
	M=0
	while N>0:
		M=M*10+N%10
		N/=10
	return M

def ispali(N):
	return reverse(N)==N

lim=[0 for i in range(7)]
for i in range(6):
	lim[i+1]=10**i

T=int(raw_input())
L=[0 for i in range(T)]
R=[0 for i in range(T)]
X=[0 for i in range(T)]

for i in range(T):
	L[i],R[i]=map(int, raw_input().split())

N=0;LIM=100000000000000
for diglen in range(5):
	if N>LIM: break
	for part in range(lim[diglen],lim[diglen+1]):
		N=part*(10**diglen)+reverse(part)
		if N>LIM: break
		if ispali(N*N):
			for i in range(T):
				if L[i]<=N*N<=R[i]:
					X[i]+=1
	for part in range(lim[diglen],lim[diglen+1]):
		if N>LIM: break
		for digadd in range(10):
			N=(part*10+digadd)*(10**diglen)+reverse(part)
			if N>LIM: break
			if ispali(N*N):
				for i in range(T):
					if L[i]<=N*N<=R[i]:
						X[i]+=1

for i in range(T):
	print ("Case #",i+1,": ",X[i],sep='')
