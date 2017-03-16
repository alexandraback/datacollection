infile = open('B.in', 'r')
outfile = open('B.out', 'w')

T = int(infile.readline())

for case_num in range(1, T+1):
	s = infile.readline().strip()
	s = s[::-1]
	prev = '+'
	cnt = 0
	for x in s:
		if x != prev:
			prev = x
			cnt += 1
	outfile.write('Case #%d: %d\n' % (case_num, cnt))

infile.close()
outfile.close()