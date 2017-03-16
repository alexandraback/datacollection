'''
7
CAB
JAM
CODE
ABAAB
CABCBBABC
ABCABCABC
ZXCASDQWE
'''

import sys

f = open(sys.argv[1],'r')
num = int(f.readline())

def solve(s):
	returner = [s[0]]
	for c in s[1:]:
		if c < returner[0]:
			returner.append(c)
		else:
			returner.insert(0,c)

	#return s+'\n'+''.join(returner)
	return ''.join(returner)
		

for i in xrange(1,num+1):
	print 'Case #'+str(i)+': '+ solve(f.readline().strip('\n'))


