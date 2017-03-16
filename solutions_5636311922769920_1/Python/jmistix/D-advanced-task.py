#input_set = "D-very-small.in"
#input_set = "D-small-attempt0.in"
input_set = "D-large.in"

def can_check_with_students(k, c, s):
	if k % c == 0:
		if (k/c) <= s:
			return True
		else:
			return False
	else: 
		if (k/c) + 1 <= s:
			return True
		else:
			return False

def check_tree(k, c, tiles):
	assert len(tiles) <= c
	p = 1
	for tile_offset in tiles:
		p = k * (p - 1) + tile_offset
	for x in xrange(c - len(tiles)):
		p = k * (p - 1) + tiles[-1]
	return p

def check_numbers(k, c, s):
	if not can_check_with_students(k, c, s):
		return "IMPOSSIBLE"
	seq_part = []
	result = []
	for i in xrange(1, k + 1):
		seq_part.append(i)
		if i % c == 0:
			result.append(check_tree(k, c, seq_part))
			seq_part = []
	if k % c != 0:
		result.append(check_tree(k, c, seq_part))
	assert len(result) <= s
	return " ".join([ str(x) for x in result])

with open(input_set) as cases:
	case_number = 0
	next(cases)

	for data in cases:
		case_number += 1
		K, C, S = [int(x) for x in data.split()]
		print "Case #{}: {}".format(case_number, check_numbers(K, C, S))