import sys

f = open(sys.argv[1],'r')
f.readline()


def solve(l):
	tiles = int(l[0])
	rows = int(l[1])
	checks = int(l[2])

	#Look at last and second to last of what would become of it.
	#Up to kth to last


#	print tiles,rows,checks
	numtocheck = tiles-1
	if tiles ==1:
		return 1
	if tiles > checks:
		return 'IMPOSSIBLE'

	if checks < numtocheck:
		return 'IMPOSSIBLE'
	if rows ==1:
		return ' '.join([str(x) for x in range(1,tiles+1)])

	else:
		return ' '.join([str(x) for x in range(2,tiles+1)])
	

	



i=1
for line in f:
	print 'Case #'+str(i)+': ' + str(solve(line.strip('\n').split(' ')))
	i+=1
