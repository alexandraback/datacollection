import time

file_in = file('test.inp', 'r')
file_out = file('test.out', 'w')

def main():
	n_case = int(file_in.readline())
	for case in range(1, n_case + 1):
		solveCase(case)

def is_single_char_str(s):
	base_c = s[0]
	for c in s:
		if c != base_c:
			return False
	return True

def has_same_char(s1, s2):
	dict_1 = {}
	for c in s1:
		dict_1[c] = True
	for c in s2:
		if c in dict_1:
			return True
	return False

def solveCase(case_number):
	#in
	n = int(file_in.readline().strip())
	car_strs = file_in.readline().strip().split()

	#main
	# find all full-same, remove it, count combination of them
	single_char_strs = {}
	distinct_char_strs = []
	for s in car_strs:
		if is_single_char_str(s):
			base_c = s[0]
			if base_c not in single_char_strs:
				single_char_strs[base_c] = 1
				distinct_char_strs.append(s)
			else:
				single_char_strs[base_c] += 1
		else:
			distinct_char_strs.append(s)


	# try connect constrains on the rest, raising unconnectable blocks
	# count number of distinct set
	# print distinct_char_strs, single_char_strs

	while True:
		found = False
		for i in range(len(distinct_char_strs)):
			if is_single_char_str(distinct_char_strs[i]):
				start_c = distinct_char_strs[i][0]
				for j in range(len(distinct_char_strs)):
					if i != j and distinct_char_strs[j][-1] == start_c:
						found = True
						break
				if found:
					distinct_char_strs[j] += distinct_char_strs[i]
					del distinct_char_strs[i]
					break
		if not found: 
			break

	while True:
		found = False
		for i in range(len(distinct_char_strs)):
			start_c = distinct_char_strs[i][0]
			# print len(distinct_char_strs)
			# print '-', i, distinct_char_strs[i], start_c
			for j in range(len(distinct_char_strs)):
				# print j, distinct_char_strs[j]
				if i != j and distinct_char_strs[j][-1] == start_c:
					found = True
					break
			if found:
				# print i, j, found
				distinct_char_strs[j] += distinct_char_strs[i]
				del distinct_char_strs[i]
				break
		if not found: 
			break

	# check false, if false, result = 0
	# in each string
	# print 'dist final', distinct_char_strs
	for s in distinct_char_strs:
		char_dict = {}
		for i in range(len(s) - 1):
			if s[i + 1] != s[i]:
				if s[i] not in char_dict:
					char_dict[s[i]] = True
				else:
					file_out.write("Case #" + repr(case_number) + ": 0\n")
					return
			if s[len(s) - 1] in char_dict:
				file_out.write("Case #" + repr(case_number) + ": 0\n")
				return

	# between strings
	for i in range(len(distinct_char_strs)):
		for j in range(i + 1, len(distinct_char_strs)):
			if has_same_char(distinct_char_strs[i], distinct_char_strs[j]):
				file_out.write("Case #" + repr(case_number) + ": 0\n")
				print i, j
				print distinct_char_strs[i]
				print distinct_char_strs[j]
				print '3'
				return

	# print 'here here here'
	result = 1
	for i in range(1, len(distinct_char_strs) + 1):
		result *= i
		result %= 1000000007

	for c in single_char_strs:
		for i in range(1, single_char_strs[c] + 1):
			result *= i
			result %= 1000000007

	#out
	file_out.write("Case #" + repr(case_number) + ": " + repr(result) + "\n")


if __name__ == '__main__':
	startTime = time.clock()
	main()
	print (time.clock() - startTime)