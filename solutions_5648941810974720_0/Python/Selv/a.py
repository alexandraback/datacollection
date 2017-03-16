n = int(raw_input())

T = [""]

for t in range(n):
	s = raw_input()
	
	d = dict()
	for l in 'ZGXUWTSVIN':
		d[l] = 0
	for i in s:
		try:
			d[i] += 1
		except:
			d[i] = 1
	ans = []
	while d['Z']:
		for l in 'ZERO':
			d[l] -= 1
		ans.append(0)
	
	while d['G']:
		for l in 'EIGHT':
			d[l] -= 1
		ans.append(8)
	while d['X']:
		for l in 'SIX':
			d[l] -= 1
		ans.append(6)
	while d['U']:
		for l in 'FOUR':
			d[l] -= 1
		ans.append(4)
	while d['W']:
		for l in 'TWO':
			d[l] -= 1
		ans.append(2)
	
	while d['T']:
		for l in 'THREE':
			d[l] -= 1
		ans.append(3)

	while d['S']:
		for l in 'SEVEN':
			d[l] -= 1
		ans.append(7)
	while d['V']:
		for l in 'FIVE':
			d[l] -= 1
		ans.append(5)
	while d['I']:
		for l in 'NINE':
			d[l] -= 1
		ans.append(9)
	while d['N']:
		for l in 'ONE':
			d[l] -= 1
		ans.append(1)


	X = ''.join(map(str,sorted(ans)))

	print 'Case #%d:'%(t+1),X
