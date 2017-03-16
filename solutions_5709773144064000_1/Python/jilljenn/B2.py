def min_time(C, F, X):
	t = 0
	nb_cookies = 0
	speed = 2
	while (X - nb_cookies) / speed >= (X - (nb_cookies - C)) / (speed + F):
		if nb_cookies < C:
			t += (C - nb_cookies) / speed
			nb_cookies = C
			continue
		nb_cookies -= C
		speed += F
	return t + (X - nb_cookies) / speed

T = int(raw_input())
for i in range(T):
	C, F, X = map(float, raw_input().split())
	print 'Case #%d: %f' % (i + 1, min_time(C, F, X))
