import re

testcase_count = int(input())

for testcase_index in range(testcase_count):
	score1_display, score2_display = input().split(" ")
	score1_regex = "^" + score1_display.replace("?", ".") + "$"
	score2_regex = "^" + score2_display.replace("?", ".") + "$"
	
	difference = 1000
	for i in range(1000):
		str_i = str(i)
		while len(str_i) < len(score1_display):
			str_i = "0" + str_i
		if re.search(score1_regex, str_i):
			for j in range(1000):
				str_j = str(j)
				while len(str_j) < len(score2_display):
					str_j = "0" + str_j
				if re.search(score2_regex, str_j):
					if abs(i - j) < difference:
						score1_result = str_i
						score2_result = str_j
						difference = abs(i - j)
						

	print("Case #%d: %s %s" % (testcase_index + 1, score1_result, score2_result))
	
