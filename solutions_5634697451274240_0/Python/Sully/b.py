import sys


'''
5
-
-+
+-
+++
--+-
'''

f = open(sys.argv[1],'r')
f.readline()


matcher = {'+':'-', '-':'+'}

def solve(s):
	s = list(s)
	flips = 0
	while s.count('-') > 0:
#		print s, flips
		last = s[-1]

		if last == '+':
			s = s[:-1]
			continue
		if s.count('-') == len(s):
			return flips+1
		else:
			first = len(s) - s[::-1].index('-')
			
			top = [matcher[x] for x in s[0:first]]
			bottom = s[first:]
			s=  top+bottom
			flips+=1
	


	return flips


i=1
for line in f:
	print 'Case #'+str(i)+': ' + str(solve(line.strip('\n')))
	i += 1
