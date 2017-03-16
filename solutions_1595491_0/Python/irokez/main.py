import sys
import math

T = int(sys.stdin.readline().strip())
for t in range(T):
	s = sys.stdin.readline().strip().split(' ')
	N = int(s.pop(0))
	S = int(s.pop(0))
	p = int(s.pop(0))
	scores = map(int, s)
	n = 0
	for score in scores:
		if score == 0:
			if p == 0:
				n += 1
			continue

		m = math.ceil(score / 3)
		if m >= p:
			n += 1
		else:
			if score % 3 != 1:
				if m >= p - 1 and S:
					S -= 1
					n += 1
	print('Case #{0}: {1}'.format(t + 1, n))
