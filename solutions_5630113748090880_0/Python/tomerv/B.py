from collections import defaultdict


def solve(n):
	nums = defaultdict(int)
	for i in range(2*n-1):
		for j in input().split():
			nums[int(j)] += 1
	res = ''
	for k,v in sorted(nums.items()):
		if v % 2 == 1:
			res += ' ' + str(k)
	return res

t = int(input())
for i in range(t):
	n = int(input())
	sol = solve(n)
	print('Case #{}:{}'.format(i+1, sol))

