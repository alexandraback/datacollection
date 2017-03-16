def ala(r, n):
	return n * (1 + 2 * r) + 2 * n * (n - 1)

T = int(raw_input())
for case in range(T):
	r, t = [int(x) for x in raw_input().split(" ")]
	
	a = 0
	b = 1
	while ala(r, b) < t:
		b *= 2
	
	while a < b:
		n = (a + b + 1) // 2
		A = ala(r, n)
		if A <= t:
			a = n
		else:
			b = n - 1
	
	assert(a == b)
	
	print "Case #" + str(case + 1) + ": " + str(a)
