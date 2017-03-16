class DigitCounter:

	def __init__(self):
		self.count = 0
		self._hash = dict()

	def _store_digit(self, digit):
		if digit not in self._hash:
			self.count += 1
			self._hash[digit] = True

	def store_number(self, number):
		if number == 0:
			self._store_digit(0)
		while number != 0:
			(number, digit) = divmod(number, 10)
			self._store_digit(digit)

with open('/home/marc/Downloads/A-large.in', 'r') as f:
	test_cases = int(f.readline())
	for test_case in xrange(1, test_cases + 1):
		n_start = long(f.readline())
		if n_start == 0:
			print 'Case #' + str(test_case) + ': INSOMNIA'
			continue
		counter = DigitCounter()
		n = n_start
		while True:
			counter.store_number(n)
			if counter.count == 10:
				print 'Case #' + str(test_case) + ': ' + str(n)
				break
			n += n_start
	