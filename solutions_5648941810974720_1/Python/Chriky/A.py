import codejam as gcj
gcj.load_input('A-large.in')

T = gcj.read_input('i')
for t in range(T):
	S = gcj.read_input('s')
	numbers = [ "ZERO", "ONE", "TWO", "THREE", "FOUR", 
				"FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
	letters = set(list(''.join(numbers)))
	counts = {l: S.count(l) for l in letters}
	keys = [('G', 'EIGHT'),
			('U', 'FOUR'),
			('W', 'TWO'),
			('X', 'SIX'),
			('Z', 'ZERO'),
			('F', 'FIVE'),
			('H', 'THREE'),
			('S', 'SEVEN'),
			('I', 'NINE'),
			('N', 'ONE')]
	answer = []

	for k, n in keys:
		N = counts[k]
		if N > 0:
			digit = str(numbers.index(n))
			answer += ([digit] * N)
			for l in n:
				counts[l] -= N
		
	print 'Case #%i:' % (t + 1), ''.join(sorted(answer))

