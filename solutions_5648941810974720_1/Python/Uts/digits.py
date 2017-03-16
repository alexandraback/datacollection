import string


def solve(counts):
	digit_counts = [0 for i in range(10)]
	digit_counts[0] = counts['Z'];
	counts['E'] -= counts['Z']
	counts['R'] -= counts['Z']
	counts['O'] -= counts['Z']
	counts['Z'] = 0

	digit_counts[2] = counts['W']
	counts['T'] -= counts['W']
	counts['O'] -= counts['W']
	counts['W'] = 0

	digit_counts[4] = counts['U']
	counts['F'] -= counts['U']
	counts['O'] -= counts['U']
	counts['R'] -= counts['U']
	counts['U'] = 0

	digit_counts[6] = counts['X']
	counts['S'] -= counts['X']
	counts['I'] -= counts['X']
	counts['X'] = 0

	digit_counts[8] = counts['G']
	counts['E'] -= counts['G']
	counts['I'] -= counts['G']
	counts['H'] -= counts['G']
	counts['T'] -= counts['G']
	counts['G'] = 0

	digit_counts[1] = counts['O']
	counts['N'] -= counts['O']
	counts['E'] -= counts['O']
	counts['O'] = 0

	digit_counts[3] = counts['H']
	counts['T'] -= counts['H']
	counts['R'] -= counts['H']
	counts['E'] -= 2*counts['H']
	counts['H'] = 0

	digit_counts[5] = counts['F']
	counts['I'] -= counts['F']
	counts['V'] -= counts['F']
	counts['E'] -= counts['F']
	counts['F'] = 0

	digit_counts[7] = counts['V']
	counts['S'] -= counts['V']
	counts['N'] -= counts['V']
	counts['E'] -= 2*counts['V']
	counts['V'] = 0

	digit_counts[9] = counts['I']
	counts['N'] -= 2*counts['I']
	counts['E'] -= counts['I']
	counts['I'] = 0

	number = ""
	for i, c in enumerate(digit_counts):
		number += str(i)*c
	return number

def parse(digits):
	counts = dict.fromkeys(string.ascii_uppercase, 0)
	for c in digits:
		counts[c] += 1
	return counts

T = int(raw_input())
for t in range(1, T+1):
	print "Case #%d: %s" % (t, solve(parse(raw_input())))
