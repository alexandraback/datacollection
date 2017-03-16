nums = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
D = {x:0 for x in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'}
def remove(a, c):
	ans[a] = c
	for x in nums[a]:
		D[x] -= c
for case in xrange(1, input() + 1):
	for x in raw_input():
		D[x] += 1
	ans = [0 for i in xrange(10)]
	remove(0, D['Z'])
	remove(2, D['W'])
	remove(4, D['U'])
	remove(6, D['X'])
	remove(8, D['G'])
	remove(1, D['O'])
	remove(3, D['T'])
	remove(5, D['F'])
	remove(7, D['V'])
	remove(9, D['E'])
	ans2 = ''
	for i in xrange(10):
		for j in xrange(ans[i]):
			ans2 += str(i)
	print "Case #" + str(case) + ": " + ans2