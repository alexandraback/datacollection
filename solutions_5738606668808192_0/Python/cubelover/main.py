import random

n = 16

print('Case #1:')

r = set()

while len(r) < 50:
	s = '1' + ''.join(random.choice(['0', '1']) for _ in range(n - 2)) + '1'
	if s in r:
		continue
	d = [0] * 11
	f = True
	for i in range(2, 11):
		t = int(s, i)
		for j in range(2, 1000):
			if not t % j:
				d[i] = j
				break
		if not d[i]:
			f = False
			break
	if f:
		r.add(s)
		print(s, end = ' ')
		for i in range(2, 10):
			print(d[i], end = ' ')
		print(d[10])