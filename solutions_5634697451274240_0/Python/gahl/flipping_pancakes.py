
def get_num_flips(s):
	last_minus = s.rfind('-')
	if last_minus == -1:
		return 0

	un_flips = 0
	prev = s[0]
	for a in xrange(1, last_minus + 1):
		if s[a] == prev:
			un_flips += 1
		prev = s[a]

	return last_minus - un_flips + 1

def main():
	num_tests = int(raw_input())
	for x in xrange(num_tests):
		order = raw_input()
		num_flips = get_num_flips(order)
		print "Case #%d: %s" % (x + 1, num_flips)

main()