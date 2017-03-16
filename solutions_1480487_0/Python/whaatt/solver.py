def solve(case):
	case = case[0]
	case = [int(i) for i in case.split(' ')][1:]
	
	num = len(case)
	pointsum = sum(case)
	
	pval = 2*pointsum/num
	
	ret = []
	for i in range(len(case)):
		val = 100*(pval-case[i])/pointsum
		ret.append(val)
		
	ct = 0	
	for i in range(len(ret)):
		if ret[i]<=0:
			ct += ret[i]
			ret[i] = 0
		
	nt = 0
	for i in range(len(ret)):
		if ret[i]>0:
			nt+=1
	
	for i in range(len(ret)):
		if ret[i]>0:
			ret[i] += ct/nt
		
	retstr = ''
	for i in range(len(ret)):
		retstr += str(ret[i]) + ' '
	
	return retstr

def process(infile,outfile,step):
	file = open(infile,'r')
	lines = file.read().splitlines()
	file.close()

	linesout = []
	toout = ''
	
	for i in range(1,int(lines[0])+1,step):
		toout = solve(lines[i:i+step])
		linesout.append('Case #' + str(i) + ': ' + str(toout) + '\n')
		toout = ''

	linesout[-1] = linesout[-1][:-1]
	
	file = open(outfile,'w')
	file.writelines(linesout)
	file.close()
	
process('A-small-attempt2.in','out',1)