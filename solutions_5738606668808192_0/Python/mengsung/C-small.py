
def digit_to_char(digit):
	if digit < 10:
		return str(digit)
	return chr(ord('a') + digit - 10)
	
def str_base(number, base):
	d, m = divmod(number, base)
	if d:
		return str_base(d, base) + digit_to_char(m)
	else:
		return digit_to_char(m)

def solve():
	multiplicand = int('100000001', 2)
	for i in range(50):
		multiplier = int('1{0:06b}1'.format(i), 2)
		print('{0:b}'.format(multiplicand * multiplier), end=' ')
		for j in range(2, 11):
			print(int('1{0:06b}1'.format(i), j), end=' ')
			#print(str_base(multiplier, j), end=' ')
		print('')

if __name__ == '__main__':
	ncase = int(input())
	for i in range(ncase):
		print('Case #{}:'.format(i+1))
		solve()
