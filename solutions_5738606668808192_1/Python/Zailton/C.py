from random import *
import math

T = input()

print ("Case #1: ")
N, J = map(int, input().split())

cnt, w = 0, (1<<(N-2))

while cnt < J and w < 1<<(N-1) :
	x = w*2 + 1
	lista = []
	val = 0
	
	for b in range (2, 11) :
		val, pot = 0, 1
		for k in range (32) :
			if x&(1<<k) : val += pot
			pot *= b
		for k in range (2, 100) :
			if (val % k) == 0 : 
				lista.append (k)
				break
		else : 
			break
	else :
		cnt += 1
		print (val, end=" ")
		for it in range (len(lista)) :
			print (lista[it], end = " ")
		print ()
	w += 1	
#print ((2**1000000000) % 103)
