import math

def readandwritefile(filein, fileout):
	with open(filein) as f:
		lines = f.readlines()
		numcases = int(lines[0].rstrip())
		linestowrite = []
		for i in range(1, (numcases+1)):
			linestowrite.append(solve(lines[i].rstrip().split()))
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






def solve(params):
	word = params[0]
	entry = ''
	for letter in word:
		if(entry == ''):
			entry += letter
		else:
			if(entry[0] <= letter):
				entry = letter + entry
			else:
				entry = entry + letter
	return entry




readandwritefile('file.in', 'file.out')