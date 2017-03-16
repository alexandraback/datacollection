T = input()

for _ in range(T):
	n = input()
	print 'Case #%d:' % (_ + 1),
	if n == 0:
		print 'INSOMNIA'
		continue
	now = n
	digits = set()
	while True:
		digits.update(list(str(now)))
		if len(digits) == 10:
			print now
			break
		now += n
