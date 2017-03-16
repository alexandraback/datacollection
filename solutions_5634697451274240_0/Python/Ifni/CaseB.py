import math
import numpy as numpy



inp=open('B-small-attempt0.in', 'r')
out=open("outputB-small", 'w')

T=int(inp.readline())
for index in range(T):
	stack=inp.readline()[:-1]
	condensedlist=[stack[0]]
	for char in stack:
		if condensedlist[0]!=char:
			condensedlist=[char]+condensedlist #Pile condensee a l'envers
	if condensedlist[0]=='+':
		out.write('Case #{}: {}\n'.format(index+1, len(condensedlist)-1))
	else:
		out.write('Case #{}: {}\n'.format(index+1, len(condensedlist)))




inp.close()
out.close()