from copy import *

f=open("D-small-attempt0.in","r")
T=int(f.readline().strip())
answers=[-1 for i in range(T)]

for i in range(T):
	N=int(f.readline().strip())
	Naomi=[float(j) for j in f.readline().split()]
	Ken=[float(j) for j in f.readline().split()]
	Naomi.sort()
	Ken.sort()
	Naomi2=deepcopy(Naomi)
	Ken2=deepcopy(Ken)
	
	dpoints=0
	points=0
	
	#Deceitful War
	if Ken[-1]==1:
		del(Naomi[0])
		del(Ken[-1])
	
	while len(Naomi):
		while len(Naomi):
			if Naomi[0]<Ken[0]:
				del(Naomi[0])
				del(Ken[-1])
			else:
				break
		if not len(Naomi):
			break
		while len(Naomi):
			if Naomi[0]>Ken[0]:
				del(Naomi[0])
				del(Ken[0])
				dpoints+=1
			else:
				break
	
	#War
	indexis=N-1
	while len(Naomi2) and indexis>=0:
		while len(Naomi2):
			if Naomi2[indexis]>Ken2[-1]:
				indexis-=1
			else:
				break
			if indexis<0:
				break
		while len(Naomi2):
			if indexis<0:
				break
			if Naomi2[indexis]<Ken2[-1]:
				indux=0
				while Ken2[indux]<Naomi2[indexis]:
					indux+=1
				del(Naomi2[indexis])
				del(Ken2[indux])
				indexis-=1
			else:
				break
		if indexis<0:
			break
	points=len(Naomi2)
			
	
	answers[i]=(dpoints,points)

f.close()

f=open("OUTPUT.txt","w")
for i in range(T):
	f.write("Case #{}: {} {}\n".format(i+1,answers[i][0],answers[i][1]))

f.close()

