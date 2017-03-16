#!/usr/bin/python3

def subtask(n, m, k):
	global solved

	v = set(map(int, input().split()))

	need = [0] * (m + 1)
	can_use = [0] * (m + 1)
	for prod in v:
		for num in range(2, m + 1):
			if prod % num == 0:
				can_use[num] = 1

			prod2 = prod
			for num2 in range(2, m + 1):
				if num != num2:
					while prod2 % num2 == 0:
						prod2 //= num2;
			
			cneed = 0
			while prod2 != 1:
				cneed += 1
				prod2 //= num

			need[num] = max(need[num], cneed)

	s = []
	for i in range(2, m + 1):
		s += [i] * need[i]
	for i in range(m, 1, -1):
		if can_use[i] > need[i]:
			s += [i]
	while len(s) < n:
		try:
			s += [(''.join(str(i) for i in can_use)).rindex('1')]
		except:
			s += [8]
	while len(s) > n:
		s.pop()

	print(''.join(str(n) for n in s))

def task():
	r, n, m, k = map(int, input().split())
	for i in range(r):
		subtask(n, m, k)

for test in range(int(input())):
	print('Case #%d:' % (test + 1))
	task()
