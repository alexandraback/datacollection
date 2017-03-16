def divs(n, j):
	#only for the 16, 50 case
	#TODO: write nice generator
	m = n - 5
	ds = []
	for a in range(m):
		d = ["0"] * m
		d[a] = "1"
		ds.append("10" + "".join(d) + "01")
		if len(ds) == j:
			return ds
		for b in range(a + 2, m):
			d = ["0"] * m
			d[a] = "1"
			d[b] = "1"
			ds.append("10" + "".join(d) + "01")
			if len(ds) == j:
				return ds
	assert False


def solve(n, j):
	ds = divs(n, j)
	for d in ds:
		bitcoin = bin(3 * int(d, 2))[2:]
		divisors = [str(int(d, b)) for b in range(2, 11)]
		print bitcoin + " " + " ".join(divisors)

t = int(raw_input())
for case in range(1, t + 1):
	n, j = map(int, raw_input().split())
	print "Case #%i:" %(case,)
	solve(n, j)
	
      
        
