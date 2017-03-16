def solve(s):
	while s.endswith("\r") or s.endswith("\n"):
		s = s[:-1]
	cnt = {}
	for w in s:
		if w in cnt:
			cnt[w] += 1
		else:
			cnt[w] = 1
	# print cnt
	ans = ""
	# print s
	# print cnt
	
	all = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
	cor = ['Z', 'O', 'W', 'T', 'U', 'F', 'X', 'V', 'G', 'I']
	
	for digit in [0, 6, 8, 2, 4, 3, 5, 7, 1, 9]:
		if (not (cor[digit] in cnt)): continue
		x = cnt[cor[digit]]
		# print digit, ":", x
		if (x == 0): continue
		ans += str(digit) * x
		for w in all[digit]:
			cnt[w] -= x
	return "".join(sorted(ans))

file = open("A-large.in", "r")
a = file.readlines()
for i in xrange(1, len(a)):
	print "Case #%d:" % i, solve(a[i])
