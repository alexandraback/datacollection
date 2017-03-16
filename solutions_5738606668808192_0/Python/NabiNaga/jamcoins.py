import random

def MillerRabin(n,k):
	if n == 2 or n == 3: return True
	size, skip = n.bit_length()-1, False
	d, s = n-1, 0
	while d%2 == 0:
		d, s = d/2, s+1
	for i in xrange(k):
		a = random.randrange(2,n-1)
		x = pow(a,d,n)
		if x == 1 or x+1 == n:
			continue
		for r in xrange(1,s):
			x = pow(x,2,n)
			if x == 1: return False
			if x+1 == n:
				skip = True
				break
		if not skip:
			return False
		skip = False
	return True

def get_factor(x):
	for i in xrange(2,100):
		if x%i == 0:
			return i
	return None

def inc(l):
	carry = 1
	ind = len(l)-2
	while carry:
		if l[ind]:
			l[ind] = 0
			ind -= 1
		else:
			l[ind] = 1
			break

def double_check(line):
	split = line.split()
	coin = split[0]
	for base in xrange(2,11):
		i = base-1
		x = int(coin,base=base)
		div = int(split[i])
		assert div < x
		assert x%div == 0

def find_coins(line):
	output = ['\n']
	n, j = [int(x) for x in line.split()]
	coin = [0]*n
	coin[0] = 1
	coin[-1] = 1
	found = 0
	while found < j:
		valid = True
		divs = []
		for base in xrange(2,11):
			value = 0
			for bit in coin:
				value *= base
				value += bit
			if MillerRabin(value,3):
				valid = False
				break
			factor = get_factor(value)
			if factor is None:
				valid = False
				break
			divs.append(factor)
		if valid:
			coin_line = ''.join([str(x) for x in coin])+' '+' '.join([str(x) for x in divs])+'\n'
			output.append(coin_line)
			found += 1
			double_check(coin_line)
		inc(coin)
	return ''.join(output)

output = []
with open('coin_input.txt') as f:
	t = int(f.readline())
	for i,line in enumerate(f):
		output.append("Case #%d: %s\n" % (i+1,find_coins(line)))

with open('coin_output.txt','w') as f:
	for line in output:
		print line,
		f.write(line)