import sys

def solve(i):
	[B, M] = map(int, sys.stdin.readline().split())
	first = '0'
	if M > 2**(B-2):
		print 'IMPOSSIBLE'
		return
	elif M == 2**(B-2):
		first = '1'
		M -= 1
	bits = bin(M)[2:]
	print 'POSSIBLE'
	for i in xrange(B-1):
		sys.stdout.write(('0' * (i+1)) + ('1' * (B-2-i)))
		if i == 0:
			print first
		elif len(bits) >= i:
			print bits[-i]
		else:
			print 0
	print '0' * B

if __name__ == '__main__':
	c = int(sys.stdin.readline())
	for i in range(c):
		sys.stdout.write('Case #%d: ' % (i+1,))
		solve(i)
