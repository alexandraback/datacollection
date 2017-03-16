testCount = int(raw_input())
for testIndex in range(testCount):
	ans = "Case #" + str(testIndex+1) + ": "
	a, b = [int(a) for a in raw_input().split(" ")]
	count = 0
	for i in range(a, b):
		used = set()
		for j in range(len(str(i))):
			i2 = int(str(i)[j:] + str(i)[:j])
			if i < i2 <= b and i2 not in used:
				count += 1
				used.add(i2)
	print (ans + str(count))
