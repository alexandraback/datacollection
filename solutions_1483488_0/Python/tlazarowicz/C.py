#!C:\Python27\python

input = file('C.input', 'r')
output = file('C.output', 'w')

num_cases = int(input.readline())

for i_case in range(1, num_cases+1):
	testcase = input.readline().strip()
	testcase_list = map(int, testcase.split(' '))
	A = testcase_list[0]
	B = testcase_list[1]
	
	results = set([])
	
	if A >= 10:
		for n in range(A, B):
			str_n = str(n)
			len_n = len(str_n)
			attempts = len(str_n) - 1
			for att in range(1, attempts+1):
				attempted = int("%s%s" % (str_n[-(att):], str_n[:len_n-att]))
				if attempted > n and attempted <= B:
					results.add((n, attempted))
	o = "Case #%d: %d" % (i_case, len(results))
	print o
	output.write(o + '\n')