import sys
import itertools

nums1 = list(enumerate(["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]))

input()
for j, d in enumerate(sys.stdin):
	nums = nums1[:]
	while True:
		c=d[:-1]
		a = []
		for i, num in nums:
			while True:
				c1 = list(c)
				f = True
				for l in num:
					if l in c1:
						c1.remove(l)
					else:
						f=False
						break
				if not f:
					break
				else:
					c = "".join(c1)
					a.append(str(i))
		if not c:
			break
		nums = nums[1:]+[nums[0]]
	print("Case #{}: {}".format(j+1, "".join(sorted(a))))
