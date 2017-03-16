t = input()
for cases in range(t):
	data = map(int, raw_input().split())
	n, s, p = data[0: 3]
	data = data[3: len(data)]
	res = 0
	for i in data:
		if i >= p + max(0, p - 1) * 2:
			res += 1
		elif s != 0 and i >=  p + max(0, p - 2) * 2:
			res += 1
			s -= 1
	print "Case #" + str(cases + 1) + ":", res
