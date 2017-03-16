file = open("D-large.in", "r")
output = open("D-large-output-OO", "w")

test_cases = file.readline()
tc = 1
choice_to_win = True

for i in file:
	X, R, C = map(int, i.split(" "))
	winner = "RICHARD"
	if X >= 7:
		choice_to_win = False
	elif X > R and X > C:
		choice_to_win = False
	elif R * C % X != 0:
		choice_to_win = False
	elif (X + 1) // 2 > min(R,C):
		choice_to_win = False
	elif X in (1,2,3):
		choice_to_win = True
	elif X == 4:
		choice_to_win = min(R,C) > 2
	elif X == 5:
		choice_to_win = not(min(R,C) == 3 and max(R,C) == 5)
	elif X == 6:
		choice_to_win = min(R,C) > 3

	if choice_to_win:
		winner = "GABRIEL"

	output.write("Case #{0}: {1}\n".format(tc, winner))
	tc += 1
