from GCJ_helper import work

def mult(x, y):
	neg = False
	if x < 0:
		neg = not neg
		x = ~x
	if y < 0:
		neg = not neg
		y = ~y
	if x == 0:
		ret = y
	elif y == 0:
		ret = x
	elif x == y:
		ret = -1
	else:
		ret = 6 - x - y
		if (y - x) % 3 == 2:
			ret = ~ret
	return ~ret if neg else ret


def solve(n, x, s):
	prod = 0
	for c in s:
		d = ord(c) - ord('h')
		prod = mult(prod, d)
	# print(prod)
	if prod == 0:
		return False
	elif prod == -1:
		if x % 2 != 1:
			return False
	elif x % 4 != 2:
		return False

	
	first_i, pref = -1, 0
	for i in range(min(4, x) * n):
		pref = mult(pref, ord(s[i % n]) - ord('h'))
		if pref == 1:
			first_i = i + 1
			break

	last_k, suff = -1, 0
	for j in range(n * x, max(x - 4, 0) * n, -1):
		suff = mult(ord(s[(j - 1) % n]) - ord('h'), suff)
		if suff == 3:
			last_k = j - 1
			break
	return first_i < last_k

def one_test():
	n, x = map(int, input().split())
	s = input()
	print('YES' if solve(n, x, s) else 'NO')

work(one_test)
