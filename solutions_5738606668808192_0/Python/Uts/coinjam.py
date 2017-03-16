def generate(N, J):
	print 'Case #1:'
	divisors = str.join(' ', [str(i) for i in range(3, 12)])
	number = ['1'] + ['0']*(N-2) + ['1']
	count = 0
	#2, 4, 6, 8, 10, 12, 14
	#1, 3, 5, 7, 9, 11, 13
	for i in range(N/2 - 1):
		for j in range(i):
			for k in range(N/2 - 1):
				for m in range(k):
					unique_number = number[:]
					unique_number[2*(i+1)] = '1'
					unique_number[2*(j+1)] = '1'
					unique_number[2*k + 1] = '1'
					unique_number[2*m + 1] = '1'
					unique_number = str.join('', unique_number)
					print "%s %s" % (unique_number, divisors)
					count += 1
					if (count == J):
						return

generate(16, 50)
