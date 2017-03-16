import math

def readandwritefile(filein, fileout):
	with open(filein) as f:
		lines = f.readlines()
		currow = 0
		numcases = int(lines[currow].rstrip())
		currow += 1
		linestowrite = []
		for i in range(1, (numcases+1)):
			linestosolve = []
			numrows = (int(lines[currow].rstrip())*2)-1
			currow += 1
			for j in range(0, numrows):
				linestosolve.append(lines[currow].rstrip().split())
				currow += 1
			linestowrite.append(solve(numrows, linestosolve))
		writeanswer(linestowrite, fileout)
		f.close()

def writeanswer(lines, file):
	with open(file, 'w+') as f:
		for i in range(0 ,len(lines)):
			line = lines[i]
			f.write("Case #" + str(i+1) + ": " + line)
			if(i+1 < len(lines)):
				f.write("\n")
		f.close()






def solve(numrows, params):
	print(params)
	dims = numrows
	rowcols = []
	nums = {}
	for i in range(0, len(params)):
		for j in range(0, len(params[i])):
			if params[i][j] in nums:
				nums[params[i][j]] += 1
			else:
				nums[params[i][j]] = 1
	ans = []
	for key, value in nums.iteritems():
		if(value%2 == 1):
			ans.append(int(key))
	ans.sort()
	entry = ""
	for i in range(0, len(ans)):
		if(i > 0):
			entry += " "
		entry += str(ans[i])
	return entry




readandwritefile('file.in', 'file.out')