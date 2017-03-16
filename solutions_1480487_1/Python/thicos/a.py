t = input()

for T in range(1, t+1):
	line = raw_input()
	v = line.split()
	val = []
	n = float(v[0])
	sum = 0.0
	for i in v[1:]:
		val.append(float(i))
		sum += float(i)
	m = n
	sum2 = sum
	med = 2*sum/n
	for i in val:
		if (i > med):
			m -= 1
			sum2 -= i
	med2 = (sum+sum2)/m
	res = 'Case #%d:' % T
	for i in val:
		if (i > med):
			val = 0.0
		else:
			val = (med2-i)/sum
		res += ' %f' % (val*100)
	print res
		