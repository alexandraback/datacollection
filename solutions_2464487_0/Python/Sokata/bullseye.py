##libraries function
import time
from math import pi

##custom file name
file_n = 'A-small-attempt0'

##template
input = open(file_n + '.in', 'r')
output = open(file_n + '.out', 'w')

n_case = int(input.readline())

start = time.clock()

def pow2(a):
	result = 0
	for i in range(1, a):
		result += 4 * i
	return result

for z in range(1, n_case+1):

	[r, t] = map(int, input.readline().split(' '))

	def rings(a):
		return 2 * a * r + a ** 2 <= t

	result = 0
	step = 1
	while True:
		circle = 2 * result * r + result + pow2(result)
		if circle > t:
			while circle > t:
				result -= 1
				circle = 2 * result * r + result + pow2(result)
			break
		result += 1
		step * 10
	
	result = max(1, result)
	print result

	output.write('Case #%s: %s\n' % (z, result))

output.close()

print "Done in %s seconds" % (time.clock() - start)
