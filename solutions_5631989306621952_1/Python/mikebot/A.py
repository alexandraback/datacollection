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
	for i in xrange(1,len(lines)):
		# DO STUFF
		word = lines[i]
		whiteboard = [word[0]]
		for l in word[1:]:
			if l >= whiteboard[0]:
				whiteboard.reverse()
				whiteboard.append(l)
				whiteboard.reverse()
			else:
				whiteboard.append(l)
		answer = ''
		for w in whiteboard:
			answer += w

		print answer
		fout.write('Case #' + str(i) + ': ' + str(answer) + '\n')
