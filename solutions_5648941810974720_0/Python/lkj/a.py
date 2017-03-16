
def fillout(s,d):
	n = []
	sd = {c: s.count(c) for c in s}
	for c in set(''.join(d)):
		if c not in sd:
			sd[c] = 0
	ic = sd['Z']
	for c in 'ZERO':
		sd[c] -= ic
	n += ['ZERO']*ic
	ic = sd['W']
	for c in 'TWO':
		sd[c] -= ic
	n += ['TWO']*ic
	ic = sd['U']
	for c in 'FOUR':
		sd[c] -= ic
	n += ['FOUR']*ic
	ic = sd['R']
	for c in 'THREE':
		sd[c] -= ic
	n += ['THREE']*ic
	ic = sd['F']
	for c in 'FIVE':
		sd[c] -= ic
	n += ['FIVE']*ic
	ic = sd['X']
	for c in 'SIX':
		sd[c] -= ic
	n += ['SIX']*ic
	ic = sd['V']
	for c in 'SEVEN':
		sd[c] -= ic
	n += ['SEVEN']*ic
	ic = sd['G']
	for c in 'EIGHT':
		sd[c] -= ic
	n += ['EIGHT']*ic
	ic = sd['I']
	for c in 'NINE':
		sd[c] -= ic
	n += ['NINE']*ic
	ic = sd['O']
	for c in 'ONE':
		sd[c] -= ic
	n += ['ONE']*ic
	return n


def solve(s):
	d = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
	r = fillout(s, d)
	for i in range(len(r)):
		r[i] = str(d.index(r[i]))
	return ''.join(sorted(r))

tc = int(input())
for t in range(1,tc+1):
	s = input()
	print('Case #{}: {}'.format(t,solve(s)))
