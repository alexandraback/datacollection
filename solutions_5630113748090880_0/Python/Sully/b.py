'''
1
3
1 2 3
2 3 5
3 5 6
2 3 4
1 2 3
'''

import sys

f = open(sys.argv[1],'r')
num = int(f.readline())

def solve(n):
#	n = int(f.readline().strip('\n'))

	fulllist = []
	missinglist= []
	n=2*int(n)-1
	for i in xrange(n):
		dummy = [fulllist.append(int(x)) for x in f.readline().strip('\n').split(' ')]

#		print fulllist

	missinglist = [x for x in fulllist if fulllist.count(x)%2]
	missinglist = list(set(missinglist))
	missinglist.sort()

	return ' '.join([str(x) for x in missinglist])
		

for i in xrange(1,num+1):
	print 'Case #'+str(i)+': '+ solve(f.readline().strip('\n'))


