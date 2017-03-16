n = int(raw_input())

def get_score(s1, s2):
	# print s1, s2
	temp1 = list(s1)
	temp2 = list(s2)
	n = len(s1)
	# print n

	# When difference not found
	has_difference = False
	for i in range(n):
		if s1[i] == "?" and s2[i] == "?":
			temp1[i] = "0"
			temp2[i] = "0"
		elif s1[i] == "?":
			temp1[i] = s2[i]
		elif s2[i] == "?":
			temp2[i] = s1[i]
		else:
			has_difference = True
			break

	# When difference is detected
	if has_difference == True:
		# print "I:", i
		sub_1 = s1[i:]
		sub_2 = s2[i:]
		# print sub_1, sub_2

		# Replace ? in s1 by 9, ? in s2 by 0
		sub_1_1 = sub_1.replace("?", "9")
		sub_2_1 = sub_2.replace("?", "0")
		# print sub_1_1, sub_2_1
		# calculate difference
		two_over_one = abs(int(sub_2_1) - int (sub_1_1))
		# print two_over_one

		# Replace ? in s1 by 0, ? in s2 by 9
		sub_1_2 = sub_1.replace("?", "0")
		sub_2_2 = sub_2.replace("?", "9")
		# print sub_1_2, sub_2_2
		# calculate difference
		one_over_two = abs(int(sub_1_2) - int (sub_2_2))
		# print one_over_two

		if two_over_one <= one_over_two:
			s1 = "".join(temp1[:i],) + sub_1_1
			s2 = "".join(temp2[:i],) + sub_2_1
		else:
			s1 = "".join(temp1[:i],) + sub_1_2
			s2 = "".join(temp2[:i],) + sub_2_2
	else:
		s1 = "".join(temp1)
		s2 = "".join(temp2)

	return " ".join([s1,s2])

for i in range(n):
	[s1, s2] = raw_input().split(" ")
	print "Case #" + str(i+1) + ": " + get_score(s1, s2)