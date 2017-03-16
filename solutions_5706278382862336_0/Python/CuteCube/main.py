#!/usr/bin/env python

def main():
	f = open('input.txt', 'r')

	total_T = int(f.readline())

	for T in xrange(1,total_T+1):
		P,Q = map(long, f.readline().rstrip('\n').split('/'))

		# print P,Q
		for i in xrange(40):
			if P*pow(2, i)%Q==0:
				P,Q = P*pow(2,i)/Q, pow(2,i)
				break
		else:
			print 'Case #{}: {}'.format(T, 'impossible')
			continue

		print 'Case #{}: {}'.format(T, gen(P,Q))

		# print N, s
		# print run(s, N)
		

		# print N,L
		# print outlets
		# print devices
		# print find(outlets, devices)

		# print 'Case #{}: {}'.format(T, run(s, N))

def gen(p, q):
	# print p,q
	if p>=q:
		return 0
	elif p%2==0 and q%2==0:
		return gen(p/2, q/2)
	elif p==1:
		return 1+gen(p,q/2)
	else:
		return 1 + gen(p-1, q/2)
		# return 1 + gen(p-p/2, q/2)


if __name__ == '__main__':
	main()