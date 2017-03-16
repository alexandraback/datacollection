import math
import numpy as numpy


out=open("outputD-small", 'w')

N=16;
J=50;
generated=[];
out.write('Case #1:\n')
for j in range(J):
	generator=str(bin(2**(N/2-1)+j*2+1))[2:];
	totalnumber=generator+generator
	res=[totalnumber]
	for j in range(2,11):
		res=res+[int(generator, j)]
	out.write('{}\n'.format(" ".join(str(i) for i in res)) )




out.close()