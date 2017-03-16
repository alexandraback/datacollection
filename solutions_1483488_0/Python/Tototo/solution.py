#!/usr/bin/python

import sys

def print_usage():
	print sys.argv[0], "<input file>", "<output file>"

def get_pair_num(A, B, str_num, handled_set):
	local_set = set()
	str_len = len(str_num)

	for i in range(str_len):
		rotate_str = str_num[i:] + str_num[:i]
		if rotate_str[0] == '0':
			continue
		rotate_num = int(rotate_str)
		if A <= rotate_num <= B:
			local_set.add(rotate_num)
			handled_set.add(rotate_num)

	local_len = len(local_set)

	return local_len * (local_len - 1) / 2

def solve(A, B):
	ret = 0
	handled_set = set()

	for num in range(A, B+1):
		if num in handled_set:
			continue
		str_num = str(num)
		ret += get_pair_num(A, B, str_num, handled_set)
	return ret

def main():
	if len(sys.argv) != 3:
		print_usage()
		return

	in_file = open(sys.argv[1], "r")
	out_file = open(sys.argv[2], "w")

	str_list = in_file.read().split()
	in_file.close()

	count, str_list = int(str_list[0]), str_list[1:]
	for i in range(1, count + 1):
		A, B, str_list = int(str_list[0]), int(str_list[1]), str_list[2:]
		out_file.write("Case #"+str(i)+": "+str(solve(A, B))+"\n")

	out_file.close()

if __name__ == "__main__":
	main()
