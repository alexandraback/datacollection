
in_file = open("in.txt")

test_cases = int(in_file.readline())

for case in range(test_cases):
	number, ovations = in_file.readline().strip().split(" ")

	needed_people = 0
	current_people = 0

	for s in range(0,int(number)+1):
		if s > current_people:
			needed_people += (s-current_people)
			current_people = s

		current_people += int(ovations[s])



	print("Case #{}: {}".format(case+1,needed_people))

