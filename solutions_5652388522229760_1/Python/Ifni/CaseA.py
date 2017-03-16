import math
import numpy as np


inp=open('A-large.in', 'r')
out=open("outputA-large", 'w')

T=int(inp.readline())
for index in range(T):
	N=int(inp.readline())
	if N==0:
		out.write('Case #{}: {}\n'.format(index+1, 'INSOMNIA'))
	else:
		arr=np.zeros((10,1))
		currentN=N
		while(True):
			temp=str(currentN)
			for char in temp:
				arr[int(char)]+=1
			if (np.prod(arr)!=0):
				break
			else:
				currentN=N+currentN;
		out.write('Case #{}: {}\n'.format(index+1, currentN))


inp.close()
out.close()