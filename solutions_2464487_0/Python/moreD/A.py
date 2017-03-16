import math

Test = int(raw_input())

for T in range(1, Test + 1):
	[r, t] = raw_input().split()
	r = int(r)
	t = int(t)
	
	k = (r + 1) * (r + 1) - r * r
	x = ((2 - k) + math.sqrt((k - 2) * (k - 2) + 8 * t)) / 4
	x = int(x)
	
	sum = (k + x + x - 2) * x
	r = r + x + x
	while sum + (r + 1) * (r + 1) - r * r <= t:
		sum += (r + 1) * (r + 1) - r * r
		x += 1
		r += 2
		
	while sum > t:
		r -= 2
		x -= 1
		sum -= (r + 1) * (r + 1) - r * r
		
	print 'Case #%d: %d' %(T, x) 