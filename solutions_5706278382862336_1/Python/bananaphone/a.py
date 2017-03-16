def gcd(a,b):
	if b==0:
		return a
	else:
		return gcd(b, a%b)

def floorpower(a, b):
	k = float(b)/a
	count = 0
	while k > 1:
		count += 1
		k /= 2
	return count

def test_den(r):
	count = 0
	while r > 1:
		if r%2 == 0:
			count +=1
			r /= 2
		else:
			return -1
	return count

T = int(raw_input())

for i in xrange(T):
	lr = raw_input()
	a, b = lr.split('/')
	a = int(a)
	b = int(b)

	x = gcd(a,b)
	a = a/x
	b = b/x

	y = test_den(b)
	if y == -1:
		ans = "impossible"
	elif y > 40:
		ans = "impossible"
	else:
		ans = floorpower(a, b)

	
	print "Case #" + str(i+1) + ": " + str(ans)
