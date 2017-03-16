import sys
cases = sys.stdin.readlines()

def compute(length, odd, even):
	def pick(string, count):
		if count == 0:
			yield string
			return
		for i in range(len(string)):
			if string[i] == '1':
				continue
			for x in pick(string[:i] + '1' + string[i+1:], count - 1):
				yield x

	odd_len = length // 2
	even_len = length - odd_len

	for odds in pick('0' * odd_len, odd):
		for evens in pick('0' * even_len, even):
			build = '1'
			odd_ind = 0
			even_ind = 0
			while True:
				if odd_ind >= len(odds):
					break
				build += odds[odd_ind]
				odd_ind += 1
				if even_ind >= len(evens):
					break
				build += evens[even_ind]
				even_ind += 1
			build += '1'
			yield build

for case in range(1, int(cases[0].strip()) + 1):
	N, J = map(int, cases[case].split())
	print 'Case #{}:'.format(case)
	for i in range(100):
		for coin in compute(N - 2, i + 2 if N % 2 else i, i):
			print '{} 3 2 5 2 7 2 9 2 11'.format(coin)
			J -= 1
			if J == 0:
				break
		if J == 0:
			break