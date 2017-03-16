
def solve():
	multiplicand = int('10000000000000001', 2)
	for i in range(500):
		multiplier = int('1{0:014b}1'.format(i), 2)
		print('{0:b}'.format(multiplicand * multiplier), end=' ')
		for j in range(2, 11):
			print(int('1{0:014b}1'.format(i), j), end=' ')
		print('')

if __name__ == '__main__':
	ncase = int(input())
	for i in range(ncase):
		print('Case #{}:'.format(i+1))
		solve()
