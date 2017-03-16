#!/usr/bin/python
import sys, string

def check_path(start, end, paths):
	if start > len(paths) or end > len(paths):
		return 0
	if start == end:
		return 1
	count = 0
	for next in paths[start]:
		count = count + check_path(next, end, paths)
	return count

#solve case function
def solve_case(paths, case_number):
	for start in range(0, len(paths)):
		for end in range(0, len(paths)):
			if start == end:
				continue
			if check_path(start, end, paths) > 1:
				print "Case #%d: Yes" % case_number
				return
	print "Case #%d: No" % (case_number)

#main
def main():
	r = sys.stdin
	if len(sys.argv) > 1:
		r = open(sys.argv[1], 'r')

	total_cases = r.readline()
	for case_number in range(1, int(total_cases) + 1):
		n = int(r.readline().strip())
		paths = []
		for i in range(0, n):
			paths.append(map(lambda x : x - 1, map(int, r.readline().strip().split(' '))[1:]))
		solve_case(paths, case_number)

# invoke main
if __name__ == "__main__":
	main()
