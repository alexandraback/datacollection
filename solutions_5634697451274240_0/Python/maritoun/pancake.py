import numpy as np
N='-'
def getAnswer(N):
	print('*******************')
	print(N)
	if(N[-1]=='\n'):
		N=N[:-1]
	i = 0
	j = len(N)-1
	print(j)
	a=np.array([],dtype=np.bool)
	for l in N:
		if(l=='+'):
			a = np.append(a,True)
		if(l=='-'):
			a = np.append(a,False)
	while j>0:
		print(j)
		if(not a[j]):#unhappy
			if(a[0]):#happy
				i += 1#flip top
				a[0] = False
			aux = np.array(a[:j+1])
			a[:j+1] = np.logical_not(aux[::-1])
			i += 1
		print(a)
		j -= 1
	if(not a[0]):#happy
		i += 1#flip top
		a[0] = True
	return i

def getAnswerBis(N):
	print('*******************')
	print(N)
	if(N[-1]=='\n'):
		N=N[:-1]
	i = 0
	j = 0
	print(j)
	a=np.array([],dtype=np.bool)
	for l in N:
		if(l=='+'):
			a = np.append(a,True)
		if(l=='-'):
			a = np.append(a,False)
	kind = a[0]
	while(j<len(a)):
		print(a)
		while(j<len(a) and a[j]==kind):
			j += 1
		kind = not kind
		if(j<len(a)):
			a[:j] = np.logical_not(a[:j])
			i += 1
	if(not a[0]):
		i+=1#all flip
	return i

results=[]
with open('B-small-attempt2.in.txt','r') as f: #B-small-attempt0.in.txt
	k=0
	for line in f:
		if(k>0):
			N = line
			results.append(getAnswerBis(N))
			if 'str' in line:
				break
		k+=1

with open('answer.txt','wb') as f:
	for i in range(len(results)):
		f.write("Case #"+str(i+1)+": ")
		f.write(str(results[i]))
		f.write("\n")

