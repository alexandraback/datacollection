f = open('B-large.in')
fw = open('B-large.out', 'w')

cases = int(f.readline())
for case in range(cases):
	state = '+'
	count = 0
	cakes = f.readline().strip()
	for s in cakes[::-1]:
		if s != state:
			count += 1
			state = s
	fw.write('Case #' + str(case + 1) + ': ' + str(count) + '\n')

fw.close()
f.close()
