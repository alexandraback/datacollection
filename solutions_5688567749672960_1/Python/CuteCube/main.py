#!/usr/bin/env python

def main():
	f = open('input.txt', 'r')

	total_T = int(f.readline())

	for T in xrange(1,total_T+1):
		N = int(f.readline().rstrip('\n'))


		# print find_speed(M)
		print 'Case #{}: {}'.format(T, resolve(N))


def resolve(N):

	n_str = [x for x in str(N)]
	# print n_str

	if len(n_str) == 1:
		return N

	if n_str[-1] == '0':
		return 1 + resolve(N - 1)

	if all(x == '0' for x in n_str[1:-1]) and n_str[0] == '1' and n_str[-1] == '1':
		# print 2
		return 2 + resolve(N - 2)

	for x in xrange(len(n_str)/2, len(n_str)):
		n_str[x] = '0'
	n_str[-1] = '1'

	c = N - int(''.join(n_str))
	if any(n_str[x]!=n_str[len(n_str)-x-1] for x in xrange(len(n_str)/2)):
		c += 1
	return c + resolve(int(''.join(reversed(n_str))))




def find_speed(M):
	v = 0
	for x in xrange(0, len(M)-1):
		if M[x] > M[x+1]:
			v = max(v, M[x]-M[x+1])

	return v


if __name__ == '__main__':
	main()