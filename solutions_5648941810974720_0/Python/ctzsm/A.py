import numpy as np

nums = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

T = int(raw_input())
for _ in xrange(T):
	mat = np.zeros((26, 10))
	for i in xrange(len(nums)):
		for c in nums[i]:
			j = ord(c) - ord('A')
			mat[j][i] += 1
	b = np.array([0] * 26)
	s = raw_input().strip()
	for c in s:
		j = ord(c) - ord('A')
		b[j] += 1

	x = np.linalg.lstsq(mat, b)
	ans = ''
	for i in xrange(10):
		for j in xrange(int(np.round(x[0][i]))):
			ans += str(i)
	print "Case #" + str(_ + 1) + ": " + ans
