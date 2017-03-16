def solve():
	l, x = (int(x) for x in input().split())
	s = input() * x
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
	for i in range(l * x):
		c = tr[s[i]]
		sgn *= sign[val][c]
		val = mult[val][c]
		if sgn == 1 and val == 1:
			break
	else:
		return 'NO'
	sgn = 1
	val = 0
	for i in range(i + 1, l * x):
		c = tr[s[i]]
		sgn *= sign[val][c]
		val = mult[val][c]
		if sgn == 1 and val == 2:
			break
	else:
		return 'NO'
	sgn = 1
	val = 0
	for i in range(i + 1, l * x):
		c = tr[s[i]]
		sgn *= sign[val][c]
		val = mult[val][c]
	if sgn == 1 and val == 3:
		return 'YES'
	return 'NO'

n = int(input())
for t in range(n):
	print("Case #{}: {}".format(t + 1, solve()))
