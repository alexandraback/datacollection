import sys

def solve(a, motes):
	assert(isinstance(a, int))
	assert(a >= 1)
	assert(isinstance(motes, list))
	for m in motes:
		assert(isinstance(m, int))
		assert(m >= 1)
	if a == 1:
		# edge case
		return len(motes)
	motes.sort()
	# print(motes)
	min_actions = len(motes)
	actions = 0
	while len(motes) > 0:
		# print(motes)
		# consume all smaller motes
		while len(motes) > 0 and motes[0] < a:
			a += motes[0]
			motes = motes[1:]
		if len(motes) == 0:
			break
		# 1st option: remove all remaining motes
		tmp_actions = actions + len(motes)
		min_actions = min(min_actions, tmp_actions)
		# 2nd option: add mote of maximal "helpful" size
		actions += 1
		a += (a-1)
	return min(min_actions, actions)


if len(sys.argv) != 2:
	print('usage: main.py <input_file>')
	exit(1)

f = open(sys.argv[1])

t = int(f.readline())

for case in range(t):
	a,n = map(int, f.readline().split())
	motes = map(int, f.readline().split())
	assert(len(motes) == n)
	res = solve(a, motes)
	print('Case #{}: {}'.format(case+1, res))
