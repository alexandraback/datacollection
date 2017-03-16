
def sum(r, k):
	return 2*r*k + k*(2*k-1)

T = int(raw_input())
for _ in range(T):
	r, t = [int(x) for x in raw_input().split()]
	#print(r, t)
	lo, hi = 0, t
	while lo < hi:
		mi = (lo + hi) // 2
		s = sum(r, mi)	
		#print(mi, s)
		if s <= t:
			lo = mi + 1
		else:
			hi = mi
	print("Case #" + str(_+1) + ": " + str(lo-1))
