def all_happy_faces(pancake_stack):
	rotated = False
	rotations = 0
	for pancake in reversed(pancake_stack):
		if (pancake == '-') != rotated:
			rotated = not rotated
			rotations += 1
	return rotations

if __name__ == "__main__":
	number_cases = int(raw_input())
	for i in range(number_cases):
		print "Case #%s: %s" % (i+1, all_happy_faces(raw_input()))
