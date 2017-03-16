from sys import argv
from os.path import expanduser

# Import the file as a list of lines:
problem = argv[1]
path = expanduser('~/Github/codejam/2016/Round1A/')
file_in = path + problem + '.in.txt'
file_out = path + problem + '.out.txt'

with open(file_in,'rb') as fin:
	lines = fin.read().splitlines()
#num_cases = int(lines[0])

with open(file_out,'wb') as fout:

	i = 1
	casenum = 1
	while i < len(lines):
		# DO STUFF
		digits = {}
		n = int(lines[i])
		for line in lines[i+1:i+2*n]:
			x = map(int, line.split())
			for number in x:
				if number in digits:
					digits[number] += 1
				else:
					digits[number] = 1
		missinglist = []
		for k,v in digits.items():
			if v%2 == 1:
				missinglist.append(k)
		missinglist.sort()
		strlist = map(str, missinglist)
	
		answer = ' '.join(strlist)
		print answer
		fout.write('Case #' + str(casenum) + ': ' + str(answer) + '\n')

		i += (2*n)
		casenum += 1
