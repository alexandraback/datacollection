import itertools


NAME = 'slides'
input_file = NAME + '.in'
output_file = NAME + '.out'


with open(input_file, 'rb') as inf, open(output_file, 'wb') as outf:
	t = int(inf.readline())
	for i in xrange(1, t+1):
		b, m = map(int, inf.readline().split())
		# if we initialize by connecting each [1, b-1] to b
		# then possibility can be translated into whether m can be factored by uniques from [1, b-1]
		# since connecting 1 with 2, ..., k+1 gains us k routes [1->b]
		# then connecting 2 with 3, ..., j+2 gains us j routes [1->2->b]
		# where k>j and k, j factors of m

		# determine if m factorizable with uniques from [1, b-1]
		# record factors along the way
		# output connections in rows with recorded factors
		outcome = ''
		for factor in xrange(b-1, 0, -1):
			if m%factor==0:
				m/=factor
				outcome += '0'*(b-factor) + '1'*factor + '\n'
			else:
				outcome += '0'*b + '\n'
		outcome += '0'*b + '\n'  # last line: b does not connect to anyone else
		if m > 1:  # did not clean divide!
			outcome = 'IMPOSSIBLE\n'
		else:
			outcome = 'POSSIBLE\n' + outcome

		# build output string
		outl = 'Case #{0}: {1}'.format(i, outcome)
		outf.write(outl)