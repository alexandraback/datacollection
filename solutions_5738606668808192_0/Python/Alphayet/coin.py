import sys

def base_to_10(num, base):
	num_10 = 0
	for i in range(len(num)):
		num_10 += num[len(num)-i-1] * (base ** i)
	return num_10

def find_divisor(num):
	if num % 2 == 0:
		return 2
	for d in range(3, int(num ** 0.5) + 1, 2):
		if num % d == 0:
			return d
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

N = 16
J = 50
j = 0
print "Case #1:"
for num in range(2 ** (N-2)):
	curr_num = to_binary(num, N-2)
	curr_num.append(1)
	curr_num[:0] = [1]
	ds = []
	for base in range(2, 11):
		num_10 = base_to_10(curr_num, base)
		divisor = find_divisor(num_10)
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
