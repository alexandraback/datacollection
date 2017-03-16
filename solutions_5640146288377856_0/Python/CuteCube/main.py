#!/usr/bin/env python

def main():
	f = open('input.txt', 'r')

	total_T = int(f.readline())

	for T in xrange(1,total_T+1):
		R, C, W = map(int, f.readline().rstrip('\n').split())

		# print R, C, W


		# print find_speed(M)
		print 'Case #{}: {}'.format(T, here(C, W))


def here(C, W):
	if C == W:
		return W
	if W == 1:
		return C
	if C >= 2*W:
		return 1 + here(C-W, W)
	if C < 2*W:
		return W+1




def find_speed(M):
	v = 0
	for x in xrange(0, len(M)-1):
		if M[x] > M[x+1]:
			v = max(v, M[x]-M[x+1])

	return v


if __name__ == '__main__':
	main()