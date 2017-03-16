from math import sqrt

Z = int(raw_input())

F = [1]

for i in xrange(120):
	F += [F[i]*(i+1)]


def binomial(n,k):
	return F[n]/F[k]/F[n-k]

def count(n):
	r = 0
	s = long(sqrt(n))
	n = len(str(s))
	#3
	if s >= 3:
		r += 1
	#[1] 2 [1]
	if s >= 2:
		r += 1
	for i in xrange(1,n/2+3):
		k = (10 ** (2*i)) + 2 * (10 ** i) + 1 
		if k > s:
			break
		r += 1
		for j in xrange(1,i):
			if (k + (10 ** j) + (10 ** (2*i-j))) <= s:
				r += 1
	#2 2
	for i in xrange(1,n+1):
		if (2 * (10 ** i) + 2) <= s:
			r += 1
	#2 1 2
	for i in xrange(1,n/2+3):
		if 2 * (10 ** (2*i)) + (10 ** i) <= s:
			r += 1
	#[1] 1 [1]
	if s >= 1:
		r += 1
	for i in xrange(1,n/2+3):
		k = (10 ** (2*i)) + (10 ** i) + 1 
		if k > s:
			break
		r += 1
		for a in xrange(1,i):
			k += (10 ** a) + (10 ** (2*i-a))
			if k <= s:
				r += 1
				for b in xrange(a+1,i):
					k += (10 ** b) + (10 ** (2*i-b))
					if k <= s:
						r += 1
						for c in xrange(b+1,i):
							if k + (10 ** c) + (10 ** (2*i-c)) <= s:
								r += 1
					k -= (10 ** b) + (10 ** (2*i-b))
			k -= (10 ** a) + (10 ** (2*i-a))
	# [1] 0 [1]
	for i in xrange(1,n/2+3):
		k = (10 ** (2*i)) + 1 
		if k > s:
			break
		r += 1
		for a in xrange(1,i):
			k += (10 ** a) + (10 ** (2*i-a))
			if k <= s:
				r += 1
				for b in xrange(a+1,i):
					k += (10 ** b) + (10 ** (2*i-b))
					if k <= s:
						r += 1
						for c in xrange(b+1,i):
							if k + (10 ** c) + (10 ** (2*i-c)) <= s:
								r += 1
					k -= (10 ** b) + (10 ** (2*i-b))
			k -= (10 ** a) + (10 ** (2*i-a))
	# [1] | [1]
	for i in xrange(1,n/2+3):
		k = (10 ** (2*i-1)) + 1 
		if k > s:
			break
		r += 1
		for a in xrange(1,i):
			k += (10 ** a) + (10 ** (2*i-1-a))
			if k <= s:
				r += 1
				for b in xrange(a+1,i):
					k += (10 ** b) + (10 ** (2*i-1-b))
					if k <= s:
						r += 1
						for c in xrange(b+1,i):
							if k + (10 ** c) + (10 ** (2*i-1-c)) <= s:
								r += 1
					k -= (10 ** b) + (10 ** (2*i-1-b))
			k -= (10 ** a) + (10 ** (2*i-1-a))
	return r
	
for z in xrange(Z):
	A, B = [long(x) for x in raw_input().split()]
	print 'Case #{0}: {1}'.format(z+1,count(B) - count(A-1))
