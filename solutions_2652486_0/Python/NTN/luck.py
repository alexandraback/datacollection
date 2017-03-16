import random

input()
input()
print('Case #1:')

for i in range(100):
	tmp = [int(i) for i in input().split()]

	p = []
	for i in tmp:
		if i != 1:
			p.append(i)

	s = []

	if any([i % 3 == 0 for i in p]):
		s.append(3)
	if any([i % 5 == 0 for i in p]):
		s.append(5)
	if any([i % 2 == 0 and i % 4 != 0 for i in p]):
		s.append(2)

	while len(s) < 3:
		diff = 3 - len(s)
		for i in range(diff):
			s.append(random.choice([2,3,4,5]))
		if s[0] * s[1] * s[2] < max(p) or min(s) > min(p) or (any([i % 2 == 0 for i in p]) and not any([i == 2 or i == 4 for i in s])):
			for i in range(diff):
				s.pop()

	for i in s:
		print(i,end='')
	print()