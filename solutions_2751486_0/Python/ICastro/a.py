def nValue(L1,n):
	cont = 0
	for x in range(len(L1)):
		if(L1[x]!='a')and(L1[x]!='e')and(L1[x]!='i')and(L1[x]!='o')and(L1[x]!='u'):
			cont+=1
			if cont == n:
				return 1
		else:
			cont=0
	return 0

def executa():
	#print(N,"_"+str(M))
	cont = 0;
	for x in range(len(L) - n + 1):
		for y in range(n,len(L) - x + 1):
			L1=L[x:x+y]
			#print(L1)
			if nValue(L1,n)==1:
				cont+=len(L) - x + 1-y
				break
	'''for x in range(n,len(L)+1):
		for y in range(len(L) - x + 1):
			L1=L[y:y+x]
			#print(L1)
			if nValue(L1,n)==1:
				cont+=1'''
	return ""+str(cont);

def main():
	T = eval(input())
	for i in range(1,T+1):
		global L,n
		L, n = input().split(' ')
		n = int(n)
		#print(L,n)
		#N, M = eval(input().replace(' ', ','))
		print('Case #'+str(i)+': '+ executa());
main()