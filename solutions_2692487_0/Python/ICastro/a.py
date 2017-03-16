def executa(vet):
	if A == 1:
		return str(N)
	tam = A
	vet = list(vet) 
	vet.sort()
	contador=0
	mini = N
	x=0
	while x<N:
		if contador+N-x<mini:
			mini = contador+N-x
		if tam>vet[x]:
			tam+=vet[x]
		else:
			tam+=tam-1
			x-=1
			contador+=1
		x+=1
	if mini<contador:
		return str(mini)
	return str(contador)

def main():
	T = eval(input())
	for i in range(1,T+1):
		global A,N
		A, N = eval(input().replace(' ', ','))
		vet = eval((input()+' ').replace(' ', ','))
		print('Case #'+str(i)+': '+ executa(vet));
main()