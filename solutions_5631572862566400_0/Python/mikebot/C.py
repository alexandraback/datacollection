from sys import argv
from os.path import expanduser
from itertools import permutations

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
		num_kids = int(lines[i])
		bffs = map(int, lines[i+1].split())
		for b in xrange(len(bffs)):
			bffs[b] -= 1
		print 'BFFS: ', bffs
		# Find the kids who are noone's BFF.  Two of them will be the "ends" of the circle.
		if len(set(bffs)) == num_kids:
			answer = num_kids
			print answer
		else:
			answer = 0
			found_any = False
			for x in xrange(3,num_kids+1):

				for p in permutations(range(num_kids),x):
					#print p
					failed = False
					for j in xrange(x):
						left = (j-1)%x
						right = (j+1)%x
						if p[left] != bffs[p[j]] and p[right] != bffs[p[j]]:
							failed = True
							break
					if not failed:
						answer = x
						found_any = True
						print x, p
						break
				if x > answer and found_any:
					break
		print 'case', casenum, answer
			



		
		fout.write('Case #' + str(casenum) + ': ' + str(answer) + '\n')
		casenum += 1
		i += 2