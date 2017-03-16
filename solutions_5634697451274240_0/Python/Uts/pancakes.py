def solve(pancakes):
	switches = 0
	for p, next_p in zip(pancakes, pancakes[1:]):
		if p != next_p:
			switches += 1
	if pancakes[0] == '+':
		return ((switches + 1)/2)*2
	return (switches/2)*2 + 1


T = int(raw_input())
for t in range(1, T+1):
	print "Case #%d: %d" % (t, solve(raw_input()))

