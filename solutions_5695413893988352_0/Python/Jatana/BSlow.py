import sys

sys.stdin = open('input.txt')
sys.stdout = open('output.txt', 'w')

A_LESS = 'A_LESS'
A_GREATER = 'A_GREATER'
EQ = 'EQ'

def ava_eq(a, b, i, force_self=True):
	r = []
	if a[i] == '?' and b[i] == '?':
		return [[A_LESS, ('0', '1')], [A_GREATER, ('1', '0')], [EQ, ('0', '0')]]
	if a[i] != '?' and b[i] != '?':
		if int(a[i]) < int(b[i]):
			return [[A_LESS, (a[i], b[i])]]
		if int(a[i]) == int(b[i]):
			return [[EQ, (a[i], b[i])]]
		if int(a[i]) > int(b[i]):
			return [[A_GREATER, (a[i], b[i])]]

	if a[i] == '?':
		if b[i] != '0':
			r.append([A_LESS, (str(int(b[i]) - 1), b[i])])
		if b[i] != '9':
			r.append([A_GREATER, (str(int(b[i]) + 1), b[i])])
		r.append([EQ, (b[i], b[i])])
		return r
	else:
		if a[i] != '0':
			r.append([A_GREATER, (a[i], str(int(a[i]) - 1))])
		if a[i] != '9':
			r.append([A_LESS, (a[i], str(int(a[i]) + 1))])
		r.append([EQ, (a[i], a[i])])
		return r
		

def boost(s, maximize=True):
	for i in range(len(s)):
		if s[i] == '?':
			if maximize:
				s[i] = '9'
			else:
				s[i] = '0'
	return s



# print(ava_eq('7', '5', 0))
mx = 1e19
best_a = None
best_b = None

def update(a, b):
	global mx
	global best_a
	global best_b
	a = ''.join(a)
	b = ''.join(b)
	mem_a = a
	mem_b = b
	a = int(a)
	b = int(b)
	if abs(a - b) <= mx:
		if abs(a - b) == mx:
			if [a, b] < [int(best_a), int(best_b)]:
				mx = abs(a - b)
				best_a = mem_a
				best_b = mem_b
		else:
			mx = abs(a - b)
			best_a = mem_a
			best_b = mem_b


def solve(a, b, qtype=0, i=0):
	avas = ava_eq(a, b, i)
	for prop in avas:
		ava = prop[0]
		ca, cb = prop[1]
		if ava == A_LESS:
			na = a[::]
			nb = b[::]
			na[i], nb[i] = ca, cb
			na = boost(na, maximize=True)
			nb = boost(nb, maximize=False)
			update(na, nb)
		if ava == A_GREATER:
			na = a[::]
			nb = b[::]
			na[i], nb[i] = ca, cb
			na = boost(na, maximize=False)
			nb = boost(nb, maximize=True)
			update(na, nb)
		if ava == EQ:
			a[i], b[i] = ca, cb
			# print(a, b)
			if i + 1 < len(a):
				solve(a, b, i=i + 1)
			else:
				update(a, b)



n = int(input())

for i in range(n):
	a, b = input().split()
	solve(list(a), list(b))
	print('Case #%d:' % (i + 1), end=' ')
	print(best_a, best_b)
	mx = 1e19
	







