#!/usr/bin/python

result = []

with open('A.in', 'r') as f:
	num = int(f.readline())
	for i in range(num):
		digit_count = 0
		digit_flag = [False] * 10
		N = int(f.readline())
		n = 0
		for i in range(10000):
			n += N
			tmp = n
			while (tmp > 0):
				digit = tmp % 10
				if not digit_flag[digit]:
					digit_count += 1
					digit_flag[digit] = True
				tmp /= 10
			if digit_count == 10:
				print n
				result.append(n)
				break
		if digit_count < 10:
			print 'INSOMNIA'
			result.append('INSOMNIA')

with open('A.out', 'w') as f:
	for i in range(len(result)):
		f.write("Case #%d: %s\n" % (i + 1, str(result[i])))

