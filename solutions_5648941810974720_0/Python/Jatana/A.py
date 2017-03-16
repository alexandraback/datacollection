import sys
sys.stdin = open('input.txt')
sys.stdout = open('output.txt', 'w')
def minus(d, word):
	for x in word:
		if d.get(x) is not None:
			d[x] -= 1

def solve(d):
	nums = [0] * 10
	rules = [
		[0, 'ZERO', 'Z'],
		[4, 'FOUR', 'U'],
		[2, 'TWO', 'W'],
		[3, 'THREE', 'R'],
		[5, 'FIVE', 'F'],
		[7, 'SEVEN', 'V'],
		[6, 'SIX', 'S'],
		[8, 'EIGHT', 'G'],
		[9, 'NINE', 'I'],
		[1, 'ONE', 'O']
	]
	for i in range(len(rules)):
		# if i == 1:
			# print(d)
		rule = rules[i]
		x, word, c = rule
		if d.get(c) is not None:
			while d[c]:
				# print(d)
				minus(d, word)
				nums[x] += 1

	r = ''
	# print (nums)
	for i in range(len(nums)):
		for j in range(nums[i]):
			r += str(i)
	return r


n = int(input())
for i in range(n):
	s = input().rstrip()
	d = dict()
	for x in s:
		d[x] = d.get(x, 0) + 1
	print('Case #%d:' % (i + 1), end=' ')
	print(solve(d))
	





