def solve(s):
	for i in range(len(s)):
		if s[i] == "+": s[i] = 1
		if s[i] == "-": s[i] = -1
	r = 0
	for i in range(len(s)):
		if s[len(s)-i-1] == 1: continue
		for j in range(len(s)-i-1): s[j] *= -1
		r += 1
	return r
testcase = input()
for i in range(testcase):
    print "Case #"+str(i+1)+":",
    print solve(list(raw_input()))
