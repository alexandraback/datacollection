##libraries function
import time

##custom file name
file_n = 'B-small-attempt1'

##template
input = open(file_n + '.in', 'r')
output = open(file_n + '.out', 'w')

n_case = int(input.readline())

start = time.clock()

for z in range(1, n_case+1):

	[E, R, N] = map(int, input.readline().split(' '))
	values = map(int, input.readline().split(' '))

	efforts = []
	e = E
	for i in range(len(values)):
		if i == len(values) - 1:
			efforts.append(e)
		elif values[i] >= max(values[i+1:]):
			efforts.append(e)
			e = R
		else:
			for (j,k) in enumerate(values[i+1:]):
				if k >= values[i]:
					break
			spend = min(e, max(e + (j+1) * R - E, 0))
			efforts.append(spend)
			e -= spend - R

	print values
	print efforts
	result = 0
	values = zip(values, efforts)
	for i in values:
		result += i[0] * i[1]

	print result

	output.write('Case #%s: %s\n' % (z, result))

output.close()

print "Done in %s seconds" % (time.clock() - start)
