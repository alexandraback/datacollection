#Last word
numLines = int(raw_input())

for line in range(numLines):
	s = raw_input()
	ans = ""
	ans += s[0]
	for c in s[1:]:
		if c >= ans[0]:
			ans = c + ans
		else:
			ans = ans + c
	print("Case #{0}: {1}".format(line+1, ans))