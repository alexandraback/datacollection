import sys

fin = open(sys.argv[1], 'r') if len(sys.argv) > 1 else sys.stdin

T = int(fin.readline())

for t in range(1, T + 1):
	B, M = map(int, fin.readline().split(' '))
	
	if (M <= 2 ** (B - 2)):
		print('Case #{0}: POSSIBLE'.format(t))
		M -= 1
		print('{0:0{size}b}1'.format(M, size = B - 1))
		for i in range(2, B + 1):
			print('{}{}'.format('0'*i,'1'*(B - i)))
	else:
		print('Case #{0}: IMPOSSIBLE'.format(t))