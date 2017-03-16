def solve():
	l, x = (int(x) for x in input().split())
	s = input() * min(x, 100)
	sgn = 1
	tr = {'1': 0, 'i': 1, 'j': 2, 'k': 3}
	mult = [[0, 1, 2, 3],
	        [1, 0, 3, 2],
	        [2, 3, 0, 1],
	        [3, 2, 1, 0]]
	sign = [[1, 1, 1, 1],
	        [1, -1, 1, -1],
	        [1, -1, -1, 1],
	        [1, 1, -1, -1]]
	sgn = 1
	val = 0
	for i in range(len(s)):
		c = tr[s[i]]
		sgn *= sign[val][c]
		val = mult[val][c]
		if sgn == 1 and val == 1:
			break
	else:
		return 'NO'
	sgn = 1
	val = 0
	for i in range(i + 1, len(s)):
		c = tr[s[i]]
		sgn *= sign[val][c]
		val = mult[val][c]
		if sgn == 1 and val == 2:
			break
	else:
		return 'NO'
	sgn = 1
	val = 0
	for i in range(i + 1, len(s)):
		c = tr[s[i]]
		sgn *= sign[val][c]
		val = mult[val][c]
	sgn1 = 1
	val1 = 0
	for i in range(l):
		c = tr[s[i]]
		sgn1 *= sign[val1][c]
		val1 = mult[val1][c]
	ressgn = 1
	resval = 0
	n = x - min(x, 100)
	while n:
		if n & 1:
			ressgn *= sgn1
			ressgn *= sign[resval][val1]
			resval = mult[resval][val1]
		sgn1 = sign[val1][val1]
		val1 = mult[val1][val1]
		n >>= 1
	sgn *= ressgn
	val = mult[val][resval]
	if sgn == 1 and val == 3:
		return 'YES'
	return 'NO'

n = int(input())
for t in range(n):
	print("Case #{}: {}".format(t + 1, solve()))
