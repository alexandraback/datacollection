#!/usr/bin/python
import sys, string

#solve case function
def solve_case(ss, case_number):
	ss_sum = float(sum(ss))
	ss_len = len(ss)
	d_per_len = (1.0 / ss_len) * 2
	print "Case #%d:" % (case_number),
	pers = []
	re_dist = 0.0
	nega_count = 0
	for s in ss:
		p = (d_per_len - (float(s) / ss_sum)) * 100
		pers.append(p)
		if p < 0.0:
			re_dist = re_dist - p
			nega_count = nega_count + 1
	pos_count = ss_len - nega_count

	for per in pers:
		if per < 0.0:
			per =  0.0
		else:
			per = per - (re_dist / pos_count)
		print "%f" % per,
	print ""

#main
def main():
	r = sys.stdin
	if len(sys.argv) > 1:
		r = open(sys.argv[1], 'r')

	total_cases = r.readline()
	for case_number in range(1, int(total_cases) + 1):
		nss = map(int, r.readline().strip().split(' '))
		solve_case(nss[1:], case_number)

# invoke main
if __name__ == "__main__":
	main()
