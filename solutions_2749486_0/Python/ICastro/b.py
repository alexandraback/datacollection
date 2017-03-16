def executa():
	saida = ""
	x=0
	y=0
	cont = 1
	if(Y>0):
		while y+2*cont+1 <= Y:
			y+=cont
			saida = saida+'N'
			cont+=1
		while True:
			if(Y-y==cont):
				y+=cont
				saida = saida+'N'
				cont+=1
			if x-cont<X:
				x+=cont
				saida = saida+'E'
				cont+=1
			else:
				x-=cont
				saida = saida+'W'
				cont+=1
			if(x==X)and(y==Y):
				break
	else:
		while y-2*cont-1 >= Y:
			y-=cont
			saida = saida+'S'
			cont+=1
		while True:
			if(Y-y==-cont):
				y-=cont
				saida = saida+'S'
				cont+=1
			if x-cont<X:
				x+=cont
				saida = saida+'E'
				cont+=1
			else:
				x-=cont
				saida = saida+'W'
				cont+=1
			if(x==X)and(y==Y):
				break
	return saida;

def main():
	T = eval(input())
	for i in range(1,T+1):
		global X,Y
		X, Y = eval(input().replace(' ', ','))
		print('Case #'+str(i)+': '+ executa());
main()