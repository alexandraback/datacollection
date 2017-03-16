import random

def fairstrategy(nweights, kweights):
	npoints=0
	kpoints=0
	numweights = len(nweights)
	for i in range(numweights, 0, -1):
		weightnum = int(random.randint(1,i))-1
		nweight = nweights.pop(weightnum-1)
		if (kweights[-1]<nweight):
			kweights.pop(0)
			npoints = npoints+1
		else:
			kpoints = kpoints+1
			for j in range(len(kweights)):
				if (kweights[j]>nweight):
					kweights.pop(j)
					break
	points = [npoints, kpoints]
	return points

def unfairstrategy(nweights, kweights):
	npoints=0
	kpoints=0
	numweights = len(nweights)
	for i in range(numweights, 0, -1):
		kweight = kweights.pop(0)
		for i in range(len(nweights)):
			if nweights[i] > kweight:
				nweights.pop(i)
				npoints = npoints + 1
				break
			if i == len(nweights)-1:
				kpoints = kpoints+1
				nweights.pop(0)
				break
	points = [npoints, kpoints]
	return points
	
lines = [line.rstrip('\n') for line in open("D-large.in")] 
outputfile = open("output.txt", 'w')
for i in range(1,int(lines[0])+1):	#number of test cases
	datastart = 1
	offset = 3*(i-1)
	nweights = sorted(map(float, lines[datastart+offset+1].split()))
	fairnweights = list(nweights)
	kweights = sorted(map(float, lines[datastart+offset+2].split()))
	fairkweights = list(kweights)
	fairpoints = fairstrategy(fairnweights, fairkweights)
	unfairpoints = unfairstrategy(nweights, kweights)
	newline = "Case #"+str(i)+": "+str(unfairpoints[0])+" "+str(fairpoints[0])+"\n"
	outputfile.write(newline)
outputfile.close()

