#input_set = "B-very-small.in"
input_set = "B-small-attempt0.in"


def count_flips(pancakes):
	sign_count = 0
	last_sign = pancakes[0]

	for pancake in pancakes:
		if pancake != last_sign:
			sign_count += 1
			last_sign = pancake
	
	if last_sign == '-':
		sign_count += 1
	return sign_count

with open(input_set) as cases:
	case_number = 0
	next(cases)

	for data in cases:
		case_number += 1
		print "Case #{}: {}".format(case_number, count_flips(data.strip()))