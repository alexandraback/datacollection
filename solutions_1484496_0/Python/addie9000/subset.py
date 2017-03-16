#!/usr/bin/python
import sys, string, itertools

#solve case function
def solve_case(nums, case_number):
	print "Case #%d: " % (case_number)
	candidate_list = []
	for i in range(1, (len(nums) + 1)):
		candidate_list.extend(itertools.combinations(nums, i))
	while len(candidate_list) > 0:
		cand = candidate_list.pop()
		sum_cand = sum(cand)
		for cand2 in candidate_list:
			if sum_cand == sum(cand2):
				print "".join("%d " % x for x in cand)
				print "".join("%d " % x for x in cand2)
				return
	else:
		print "Impossible"

#main
def main():
	r = sys.stdin
	if len(sys.argv) > 1:
		r = open(sys.argv[1], 'r')

	total_cases = r.readline()
	for case_number in range(1, int(total_cases) + 1):
		nums = map(int, r.readline().strip().split(' '))
		solve_case(nums[1:], case_number)

# invoke main
if __name__ == "__main__":
	main()
