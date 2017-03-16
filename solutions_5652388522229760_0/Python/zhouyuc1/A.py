infile = open('A.in', 'r')
outfile = open('A.out', 'w')

T = int(infile.readline())

for case_num in range(1, T+1):
	N = int(infile.readline())
	if N == 0:
		outfile.write('Case #%d: INSOMNIA\n' % case_num)
		continue
	mrk = [0]*10
	i = 1
	while True:
		num = N*i
		i += 1
		tmp = num
		while tmp > 0:
			mrk[tmp%10] = 1
			tmp //= 10
		if sum(mrk) == 10:
			break
	outfile.write('Case #%d: %d\n' % (case_num, num))

infile.close()
outfile.close()