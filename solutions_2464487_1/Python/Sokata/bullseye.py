##libraries function
import time
from math import pi, sqrt

##custom file name
file_n = 'A-large'

##template
input = open(file_n + '.in', 'r')
output = open(file_n + '.out', 'w')

n_case = int(input.readline())

start = time.clock()


for z in range(1, n_case+1):

	[r, t] = map(int, input.readline().split(' '))

	det = (2 * r - 1) ** 2 + 4 * 2 * t
	result = int((-2 * r + 1 + sqrt(det)) / 4)

	if result * 2 * r - result + 2 * result ** 2 > t:
		result -= 1
	
	result = max(1, result)
	print result

	output.write('Case #%s: %s\n' % (z, result))

output.close()

print "Done in %s seconds" % (time.clock() - start)
