##libraries function
import time, re

##custom file name
file_n = 'A-small-attempt0'

##template
input = open(file_n + '.in', 'r')
output = open(file_n + '.out', 'w')

n_case = int(input.readline())

start = time.clock()

for z in range(1, n_case+1):

	[name, n] = input.readline().split(' ')
	n = int(n)

	r = re.compile(r"[bcdfghjklmnpqrstvwxyz]{" + str(n) + "}")

	result = 0

	for i in range(n, len(name) + 1):
		for j in range(0, len(name) + 1 - i):
			if r.findall(name[j:j+i]):
				result += 1

	assert(result <= len(name) * (len(name)+1) / 2)

	output.write('Case #%s: %s\n' % (z, result))

output.close()

print "Done in %s seconds" % (time.clock() - start)
