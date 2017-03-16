cn, t = 0, int(input())
while cn < t:
	cn = cn + 1
	print("Case #%d:" % (cn,), end = '')
	s = list(map(int, input().split()))
	n, s = s[0], s[1:]
	SUM = sum(s)
	for i in range(len(s)):
		cnt, low, high = 0, 0.0, 1.00
		while cnt <= 100:
			mid = (low + high) / 2
			score = s[i] + SUM * mid
			vsum = mid
			#print("%d _ %.5lf __ %.5lf\n" % (i, score, vsum))			
			for j in range(len(s)):
				if j == i: continue
				temp = max((score - s[j]) / SUM, 0)
				vsum += temp
				#print("\t%d _ %.5lf __ %.5lf\n" % (j, temp, vsum))
			if vsum < 1.0: low = mid
			else: high = mid
			cnt = cnt + 1
		print(" %.6lf" % (low * 100,), end = '')
	print("")
	