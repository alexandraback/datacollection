import sys

if len(sys.argv) > 1:
	filename = sys.argv[1]
	f = open(filename,'r')
	count = 0
	
	outF = open('passwordOut.txt','w+')
	numTC = int(f.readline())
	
	for case in range(numTC):
		line = f.readline()
		nums = line.split()
		A = int(nums[0])
		B = int(nums[1])
		line = f.readline()
		p = line.split()
		probRight = [1];
		min = B+2
		
		for i in range(A):
			p[i] = float(p[i])
			probRight.append(p[i]*probRight[i])
			keyStrokesIfRight = (A-i)*2 + B-A + 1
			keyStrokesIfWrong = keyStrokesIfRight+B+1
			expectedKeystrokes = keyStrokesIfRight*probRight[i] + keyStrokesIfWrong*(1-probRight[i])
			if expectedKeystrokes < min:
				min = expectedKeystrokes
		if A < B:
			keyStrokesIfRight = B-A+1
			keyStrokesIfWrong = keyStrokesIfRight+B+1
			expectedKeystrokes = keyStrokesIfRight*probRight[-1] + keyStrokesIfWrong*(1-probRight[-1])
			if expectedKeystrokes < min:
				min = expectedKeystrokes
		
		casenum = case+1
		out = "Case #%d: " %  casenum
		out = out + str(min) + "\n"
		print out
		outF.write(out)
		outF.flush()
	outF.close()