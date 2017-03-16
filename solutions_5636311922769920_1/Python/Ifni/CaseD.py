import math
import numpy as numpy


def findid(K, start, end, minprop):
	index=start;
	for i in range(end-start):
		index=K*(index-1)+(i+1+start)
	while end-start<minprop:
		index=K*(index-1)+1
		minprop-=1
	return index

inp=open('D-large.in', 'r')
out=open("outputD-large", 'w')

T=int(inp.readline())
for index in range(T):
	K, C, S=(int (val) for val in inp.readline().split())
	if (K==1):
		out.write('Case #{}: {}\n'.format(index+1, 1 ))
	elif ((K//C+1>S and C*(K//C) != K) or (K//C>S and C*(K//C) == K )):
		out.write('Case #{}: {}\n'.format(index+1, 'IMPOSSIBLE' ))
	else:
		ind=1;
		if (K<=C):
			ind=findid(K,1,K,C-1)
			out.write('Case #{}: {}\n'.format(index+1, ind))
		else:
			res=[findid(K, i, min(i+C-1,K), C-1) for i in range(1,K+1,C)]
			out.write('Case #{}: {}\n'.format(index+1, " ".join(str(i) for i in res)))


inp.close()
out.close()