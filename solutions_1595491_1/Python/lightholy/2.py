testCount = int(raw_input())
for testIndex in range(testCount):
	ans = "Case #" + str(testIndex+1) + ": "
	data = [int(a) for a in raw_input().split(" ")]
	n = data[0]
	s = data[1]
	p = data[2]
	t = data[3:]
	c1 = sum([1 if i >= p * 3 - 2 else 0 for i in t])
	c2 = sum([1 if i >= (p * 3 - 4 if p != 1 else 1) else 0 for i in t]) - c1
	ans += str(c1 + min(c2, s))
	print (ans)
