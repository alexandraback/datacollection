import sys

B = 0
P = []
N = {}
def get_num(k):
	global N
	if k in N:
		return N[k]

	if k == 0:
		N[k] = B + 1
		return N[k]

	# case 1: press enter and retype
	n_enter = 1 + get_num(0)

	# case 2: keep typing
	p_right = 1
	for i in range(k):
		p_right *= P[i]
	n_type = p_right * (B - k + 1) + (1 - p_right) * (B - k + 1 + B + 1)

	# case 3: backspace
	min_n = min(n_enter, n_type)
	for i in range(k, 0, -1):
		n_back = 1 + get_num(i - 1)
		if n_back < min_n:
			min_n = n_back

	N[k] = min_n

	return N[k]

T = int(sys.stdin.readline().strip())
for t in range(T):
	A, B = map(int, sys.stdin.readline().strip().split(' '))
	P = list(map(float, sys.stdin.readline().strip().split(' ')))
	N = {}	
	n = get_num(A)
	#print(N)
	print('Case #{0}: {1:.6f}'.format(t + 1, n))
