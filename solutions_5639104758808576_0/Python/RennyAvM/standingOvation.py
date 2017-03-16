import numpy as np

def standingOvation(Smax, L):

	if Smax == 0:
		ret = 0
	else:
		L1 = range(1,Smax+1)
		L2 = np.cumsum(L[:-1])
		n = max(L1 - L2)
		ret = max([0,n])
		
	return ret



# main
f = open("A-small-attempt1.in", 'r') 
f_out = open("A-small-attempt1.out", 'w') 

line = f.readline()
T = int(line)

i=1
for line in f:
	s = line.split(' ')  # s[0] is max shyness (str),  s[1] is number of people with shyness i, including \n 
	smax = int(s[0])
	s = s[1][:-1]  # number of people with shyness i, \n removed
	L = [int(d) for d in s]
	
	n = standingOvation(smax, L)
	
	f_out.write("Case #{0}: {1}\n".format( i, n ) )
	
	i=i+1

f.close()
f_out.close()
