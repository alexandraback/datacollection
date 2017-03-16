import math

rep = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
dzielnik = [0,0,0,0,0,0,0,0,0,0,0,0,0,0]

def to_base(x):
	pot = 1
	res = 0
	for i in range(0,32):
		res += rep[i] * pot
		pot *= x
	
	return res


def pierwsza(x, akt_baza):
	
	for i in range(2,50000):
		if x % i == 0:
			dzielnik[akt_baza] = i
			return 0
		
	
	return 1

def prog():
	n = 32
	J = 500
	zla = 0
	ilosc = 0
	res = 0
	
	print "Case #1: \n"
	
	#for i in range(2147483649,4294967296,2):
	for i in range(2147483649,2147493649,2):
		
		x = i
		ind = 0
		
		while x > 0:
			rep[ind] = x % 2
			x = x / 2
			ind = ind + 1
		 
		
		zla = 0
		
		for j in range(2,11):
			res = to_base(j)
		
			if pierwsza(res, j) == 1:
				zla = 1;
				
		
		if zla == 0:
			s = ''
		
			for j in range(31,-1,-1):
				s += `rep[j]`
			
			for j in range(2,11):
				s += ' ' + `dzielnik[j]` 
			
			print s
			
			ilosc = ilosc + 1
		
			if ilosc == J:
				return

prog()
