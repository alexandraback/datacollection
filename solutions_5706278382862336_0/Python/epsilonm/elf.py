def biggest(p, q, power=0):
	a, b = 1, 2**power
	while True:
		if a * q <= b * p:
			return a, b, power
		b *= 2
		power += 1

def subtract(p, q, a, b):
	x, y = (p * b - a * q), (q * b)
	if not x:
		return x, 1
	#g = gcd(x, y)
	return x,y#(x/g), (y/g)
	
def gcd(a, b):
	while b:
		a, b = b, a % b
	return a


t = int(input())

for i in range(1, t+1):
	p, q = map(int, input().split('/'))
	answer = None
	first_power = None
	power = 0
	while p:
		a, b, power = biggest(p, q, power)
		if first_power is None:
			first_power = power
		if power > 40:
			answer = 'impossible'
			break
		p, q = subtract(p, q, a, b)
	if answer != 'impossible':
		answer = first_power

	print('Case #%s: %s' % (i, answer))




