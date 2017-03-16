def digits(x):
	ans = 0
	while (x > 0):
		x = x / 10
		ans = ans + 1
	return ans
def reverse(x, n):
	ans = 0
	for i in xrange(n):
		ans = ans + (x % 10) * (10 ** (n - i - 1))
		x = x / 10
	
	return ans

def inverse(x):
	ans = 0
	num = digits(x)
	for i in xrange(num):
		ans = ans + (x % 10) * (10 ** (num - i - 1))
		x = x / 10
	return ans
def g(x):
	y = x
	num = digits(x)
	tens = 1
	right = 0
	for i in xrange((num + 1) / 2):
		right = right + tens * (x % 10)
		tens = tens * 10
		x = x / 10
	left = 0
	for i in xrange((num) / 2):
		left = left * 10 + x % 10
		x = x / 10
	
	#print left, right
	if num == 1:
		return y
	if left == 1:
		return right
	elif right == 0:
		#print 10 ** (num - 1)
		#return y - 10 ** (num - 1)
		first = left - 10 ** (digits(left) - 1)
		for i in xrange(digits(left), (num ) / 2):
			first = first + 9 * (10 ** i)
		if (first == 1):
			#print y - 10 ** (num - 1)
			return y - 10 ** (num - 1)
		#print first
		tmp = reverse(first, num)
		#print tmp
		second = y - (tmp + 1)
		#print second
		return first + second + 1
	else:
		return left + right

def f(x):
	ans = 0
	num = digits(x)
	target = 0
	for i in xrange(num - 1):
		target = target * 10 + 9
		tmp = g(target) + 1
		#print tmp
		ans = ans + tmp 
	#print g(x)
	ans = ans + g(x)
	return ans

#print f(123)
#print f(23)
#print f(120000000)
#print f(101000)
#print f(101000)
#print f(110000)
#print f(11000)


#print inverse(128738912783)
#sy ={}
#sy[0] = 0
#for i in xrange(1, 100000000):
#	sy[i] = sy[i - 1] + 1
#	if inverse(i) < i and digits(inverse(i)) == digits(i):
#		tmp1 = sy[inverse(i)] + 1
#		if (tmp1 < sy[i]):
#			sy[i] = tmp1
#	if sy[i] != f(i):
#		print i, sy[i], f(i)
num = input()
for test in xrange(num):
	x = input()
	print "Case #" + str(test + 1) + ":", f(x)
