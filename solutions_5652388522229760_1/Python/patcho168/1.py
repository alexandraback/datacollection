f = open('large1.in')
T = int(f.readline().strip())

i = 0
for k in range(T):
	num = int(f.readline().strip())
	allDigits = [0] * 10
	i+=1
	if (num == 0):
		print "Case #%d: INSOMNIA" %i
		continue
	increaseNum = num
	while True:
		tempNum = num
		while (tempNum > 0):
			digit = tempNum % 10
			allDigits[digit] = 1
			tempNum = tempNum/10
		if (sum(allDigits) == 10):
			break
		num = num + increaseNum
	print "Case #%d: %d" %(i, num)
		