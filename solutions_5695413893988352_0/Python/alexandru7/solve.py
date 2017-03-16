
no_tests = int(input())

for test_no in range(no_tests):
	score_jam, score_code = input().split(" ")

	jam_no = 0
	code_no = 0

	for i in range(len(score_jam)):
		if score_jam[i] == '?' and score_code[i] == '?':
			if jam_no == code_no:
				jam_no *= 10
				code_no *= 10
			if jam_no < code_no:
				jam_no = jam_no*10 + 9
				code_no = code_no*10

			if jam_no > code_no:
				jam_no = jam_no*10
				code_no = code_no*10 + 9

		elif score_jam[i] == '?':
			digit = int(score_code[i])
			if jam_no == code_no:
				jam_no = jam_no*10 + digit;
				code_no = code_no*10 + digit;

			if jam_no < code_no:
				jam_no = jam_no*10 + 9
				code_no = code_no*10 + digit

			if jam_no > code_no:
				jam_no = jam_no*10 
				code_no = code_no*10 + digit

		elif score_code[i] == '?':
			digit = int(score_jam[i])
			if jam_no == code_no:
				jam_no = jam_no*10 + digit;
				code_no = code_no*10 + digit;

			if jam_no < code_no:
				jam_no = jam_no*10 + digit
				code_no = code_no*10

			if jam_no > code_no:
				jam_no = jam_no*10 + digit
				code_no = code_no*10 + 9
		else:
			digit_jam = int(score_jam[i])
			digit_code = int(score_code[i])
			jam_no = jam_no*10 + digit_jam
			code_no = code_no*10 + digit_code

	jam_no = str(jam_no)
	code_no = str(code_no)

	jam_no = "0"*(len(score_jam) - len(jam_no)) + jam_no
	code_no = "0"*(len(score_code) - len(code_no)) + code_no

	print("Case #{}: {} {}".format(test_no+1,jam_no,code_no))