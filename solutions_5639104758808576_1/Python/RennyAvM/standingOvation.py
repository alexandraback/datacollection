import numpy as np

def standingOvation(Smax, L):

	if Smax == 0:
		# everyone claps instantly, no friends needed.
		ret = 0
	else:
		L1 = range(1,Smax+1) # 1..Smax
		L2 = np.cumsum(L[:-1])
		# sum up everyone with shyness level 0..i-1. at level i, that sum needs to be at least i, so add a few friends with shyness 0.  
		n = max(L1 - L2)
		ret = max([0,n])
		
	return ret



# main
f = open("A-large.in", 'r') 
f_out = open("A-large.out", 'w') 

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
