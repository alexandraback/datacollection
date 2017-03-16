import time

possible_prime = [4, 11, 19, 25, 26, 31, 40, 41]

def base_to_10(num, base):
	num_10 = 0
	for i in xrange(len(num)):
		num_10 += num[len(num)-i-1] * (base ** i)
	return num_10

def find_divisor(num, start_time):
	if num % 2 == 0:
		return 2
	for d in xrange(3, int(num ** 0.5) + 1, 2):
		if num % d == 0:
			return d
		if time.time() - start_time > 3:
			return False
	return False

def to_binary(k, n):
	b = [0] * n
	i = 0
	while k > 0:
		b[i] = k % 2
		k = k / 2
		i += 1
	b.reverse()
	return b

N = 32
J = 500
j = 0
print "Case #1:"
for num in xrange(2 ** (N-2)):
	if num not in possible_prime:
		curr_num = to_binary(num, N-2)
		curr_num.append(1)
		curr_num[:0] = [1]
		ds = []
		for base in range(2, 11):
			num_10 = base_to_10(curr_num, base)
			start_time = time.time()
			divisor = find_divisor(num_10, start_time)
			if not divisor:
				break
			else:
				ds.append(divisor)
		else:
			print ''.join(map(lambda x: str(x), curr_num)), ' '.join(map(
				lambda x: str(x), ds))
			j += 1
		if j == J:
			break
