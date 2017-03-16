import re
import numpy as np

f = open("in.in","r")
w = open("output.txt","w")
num = f.readline()
for it in range(0,int(num)):
	
	J,P,S,K = [int(l) for l in f.readline().split()]
	JPcomb = np.zeros((J,P),np.uint16)
	JScomb = np.zeros((J,S),np.uint16)
	PScomb = np.zeros((P,S),np.uint16)
	
	amt = 0
	res = []
	#totalCombination = J*P*S
	#	if K>=S:
	for j in range(J):
		for p in range(P):
			for s in range(S):
				if(JPcomb[j,p]>=K):
					continue
				if(JScomb[j,s]>=K):
					continue
				if(PScomb[p,s]>=K):
					continue
				comb = '{0} {1} {2}'.format(j+1,p+1,s+1)
				JPcomb[j,p] += 1
				JScomb[j,s] += 1
				PScomb[p,s] += 1
				res.append(comb)
				amt +=1
	
	
	#simple number result
	print("Case #{0}: {1} ".format(it+1,amt))
	w.write("Case #{0}: {1}\n".format(it+1,amt))
	#string list result
	res = '\n'.join(res)
	print('{}'.format(res))
	w.write('{}'.format(res))
	print()
	w.write('\n')
w.close()