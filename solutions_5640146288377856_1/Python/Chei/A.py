testcase_count = int(input())
for testcase_index in range(1, testcase_count + 1):
	rows, columns, width = [int(x) for x in input().split()]
	scan_per_row = columns // width
	result = scan_per_row * rows
	result += width
	if width == 1 or columns % width == 0:
		result -= 1

	print("Case #%d: %d" % (testcase_index, result))