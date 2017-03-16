from sys import stderr
import threading

def calc(a, b, r, i):
	for num in xrange(a, b + 1):
		num2 = str(num)
		rots = set()
		for rot in range(len(num2) - 1):
			num2 = num2[1:] + num2[0]
			num2i = int(num2)
			if num2i <= b and num2i > num:
				rots.add(num2i)
		r[i] += len(rots)

n = int(raw_input())
r = [0] * n
t = []

for i in range(n):
	a, b = map(int, raw_input().split())
	t.append(threading.Thread(target = calc, args = [a, b, r, i]))
	t[-1].start()

for i in range(n):
	t[i].join()

for i in range(n):
	print 'Case #%d: %d' % (i + 1, r[i])
