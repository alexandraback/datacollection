import math

matriz=[]
def executa():
	n = int((-3-2*r+math.sqrt(4*r*r-4*r+8*t+1))/4+1)
	while (2*n*r+n+2*n*(n+1)+2*r+1<t):
		n+=1
	while (2*n*r+n+2*n*(n+1)+2*r+1>t):
		n-=1
	return n+1

def main():
	T = eval(input())
	for i in range(1,T+1):
		global r,t
		r, t = eval(input().replace(' ', ','))
		print('Case #'+str(i)+':', executa());
		matriz=[]
main()