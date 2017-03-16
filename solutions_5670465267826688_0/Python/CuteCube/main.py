#!/usr/bin/env python


def main():
	f = open('input.txt', 'r')

	total_T = int(f.readline())

	table = {}
	table['1'] = {}
	table['1']['1'] = '1'
	table['1']['i'] = 'i'
	table['1']['j'] = 'j'
	table['1']['k'] = 'k'
	table['i'] = {}
	table['i']['1'] = 'i'
	table['i']['i'] = '-1'
	table['i']['j'] = 'k'
	table['i']['k'] = '-j'


	for T in xrange(1, total_T + 1):
		L, X = map(int, f.readline().rstrip('\n').split())
		S = f.readline().rstrip('\n')

		if X > 4:
			X = X % 4 + 4

		S = S * X

		# check sum
		sign, char = 1, '1'
		for x in S:
			temp_sign, char = mul(char, x)
			sign = temp_sign*sign
		# sign, char = mul('1', S)
		if sign != -1 or char != '1':
			print 'Case #{}: {}'.format(T, 'NO')
			continue

		# check leading i
		f_sign, f_char = 1, '1'
		x = -1		
		while (f_sign != 1 or f_char != 'i') and x < len(S) -1:
			x += 1
			sign, char = mul(f_char, S[x])
			f_sign, f_char = f_sign*sign, char

		# check tailing k
		t_sign, t_char = 1, '1'
		y = len(S)
		while (t_sign != 1 or t_char != 'k') and y > 0:
			y -= 1
			sign, char = mul(S[y], t_char)
			t_sign, t_char = t_sign*sign, char
		if x < y:
			print 'Case #{}: {}'.format(T, 'YES')
		else:
			print 'Case #{}: {}'.format(T, 'NO')



		# print mul('1', S)
		

		# print 'Case #{}: {}'.format(T, sovler(0, S, d, cache))

def mul(a, b):
	if len(a) == 1 and len(b) == 1:
		if a == '1':
			return 1, b
		if b == '1':
			return 1, a
		# if a == -1:
		# 	return -1, b
		# if b == -1:
		# 	return -1, a
		if a == b:
			return -1, '1'
		if a == 'i' and b == 'j':
			return 1, 'k'
		if a == 'i' and b == 'k':
			return -1, 'j'
		if a == 'j' and b == 'k':
			return 1, 'i'
		if a == 'j' and b == 'i':
			return -1, 'k'
		if a == 'k' and b == 'j':
			return -1, 'i'
		if a == 'k' and b == 'i':
			return 1, 'j'

	if len(a) > 1:
		sign1, char1 = mul(a[1:], b)
		sign2, char2 = mul(a[0], char1)
		return sign1*sign2, char2
	if len(b) > 1:
		sign1, char1 = mul(b[0], b[1:])
		sign2, char2 = mul(a, char1)
		return sign1*sign2, char2

	raise Exception(a, b)





if __name__ == '__main__':
	main()