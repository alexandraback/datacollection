#!/usr/bin/python
import sys, string

#solve case function
def solve_case(leveldata, case_number):
	leveldata.sort(lambda x, y: y[1] - x[1])
	stars = 0
	times = 0
	levelcleard = [[0] * len(leveldata), [0]* len(leveldata)]
	while 0 in levelcleard[1]:
		for i in range(0, len(leveldata)):
			if (levelcleard[1][i] == 0 and leveldata[i][1] <= stars):
				levelcleard[1][i] = 1
				times = times + 1
				if (levelcleard[0][i] == 0):
					stars = stars + 2
				else:
					stars = stars + 1
				break
		else:
			for i in range(0, len(leveldata)):
				if (levelcleard[1][i] == 0 and levelcleard[0][i] == 0 and leveldata[i][0] <= stars):
					levelcleard[0][i] = 1	
					times = times + 1
					stars = stars +1
					break
			else:
				print "Case #%d: Too Bad" % case_number
				return
	print "Case #%d: %d" % (case_number, times)

#main
def main():
	r = sys.stdin
	if len(sys.argv) > 1:
		r = open(sys.argv[1], 'r')

	total_cases = r.readline()
	for case_number in range(1, int(total_cases) + 1):
		levels = int(r.readline().strip())
		leveldata = [] 
		for level_number in range(0, levels):
			leveldata.append(map(int, r.readline().strip().split(' ')))
		solve_case(leveldata, case_number)

# invoke main
if __name__ == "__main__":
	main()
