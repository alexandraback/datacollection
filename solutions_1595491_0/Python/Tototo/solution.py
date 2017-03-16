#!/usr/bin/python

import sys

def print_usage():
	print sys.argv[0], "<input file>", "<output file>"

def solve(N, S, p, scores):
	S_count = S
	ret = 0

	if p == 0:
		return N

	for score in scores:
		if   score >= 0 and (score + 0) % 3 == 0 and (score + 0) / 3 >= p:
			ret += 1
		elif score >= 2 and (score + 1) % 3 == 0 and (score + 1) / 3 >= p: 
			ret += 1
		elif score >= 1 and (score + 2) % 3 == 0 and (score + 2) / 3 >= p: 
			ret += 1
		elif score >= 3 and (score + 3) % 3 == 0 and (score + 3) / 3 >= p and S_count > 0: 
			ret += 1
			S_count -= 1
		elif score >= 2 and (score + 4) % 3 == 0 and (score + 4) / 3 >= p and S_count > 0: 
			ret += 1
			S_count -= 1

	return ret

def main():
	if len(sys.argv) != 3:
		print_usage()
		return

	in_file = open(sys.argv[1], "r")
	out_file = open(sys.argv[2], "w")

	str_list = in_file.read().split()
	in_file.close()

	count, num_list = int(str_list[0]), [ int(x) for x in str_list[1:] ]
	for i in range(1, count + 1):
		N, S, p = num_list[0], num_list[1], num_list[2]
		scores, num_list = num_list[3:3+N], num_list[3+N:]
		out_file.write("Case #"+str(i)+": "+str(solve(N, S, p, scores))+"\n")

	out_file.close()

if __name__ == "__main__":
	main()
