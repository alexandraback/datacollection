t = int(raw_input())
for case in range(1, t + 1):
	b, m = map(int, raw_input().split())
	if m > 2 ** (b - 2):
		print "Case #%i: IMPOSSIBLE" %(case)
	else:
		mat = [["0"] * b for _ in range(b)]
		for r in range(b):
			for c in range(r + 1, b - 1):
				mat[r][c] = "1"
		if m == 2 ** (b - 2):
			for r in range(b - 1):
				mat[r][b - 1] = "1"
		else:
			r = 1
			while m:
				if m % 2:
					mat[r][b - 1] = "1"
				m /= 2
				r += 1
			while r < b - 1:
				for c in range(b):
					mat[r][c] = "0"
					mat[c][r] = "0"
				r += 1
		print "Case #%i: POSSIBLE" %(case)
		for row in mat:
			print " ".join(row)

      
        
