def solve_recurse(state, state_links, i, b, m):
	if i == b + 1:
		if state[b] == m:
			return state
		return None

	for j in xrange(0, 2**(i-1)): # possible sums instead
		x = 1
		state[i] = 0
		state_links[i] = []
		while j > 0:
			if j & 1 == 1:
				state[i] += state[x]
				state_links[i].append(x)
				# print "added: %d at %d" % (state[x], x)
			j >>= 1
			x += 1
		#print state[i]
		res = solve_recurse(state, state_links, i+1, b, m)
		if res:
			return res
	state.pop(i)

def fill(l, b):
	nl = [0]*b
	for a in l:
		nl[a-1] = 1
	return ''.join(str(a) for a in nl)

def one(line):
	b, m = [int(a) for a in line.split()]

	state = {
		1: 1,
	}

	state_links = {}

	res = solve_recurse(state, state_links, 2, b, m)
	if res is None:
		return "IMPOSSIBLE"
	else:
		s = []
		sl2 = {}
		for k,v in state_links.iteritems():
			for n in v:
				if n not in sl2:
					sl2[n] = []
				sl2[n].append(k)
		for a in xrange(1, b + 1):
			if a not in sl2:
				s.append('0'*b)
			else:
				s.append(fill(sl2[a], b))
		return "POSSIBLE\n%s" % '\n'.join(s)

def main():
	num_tests = int(raw_input())
	for x in xrange(num_tests):
		num = raw_input()
		print "Case #%d: %s" % (x + 1, one(num))

main()