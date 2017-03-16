f = open("A-small-attempt2.in", "r")
output = open("A-small-output", "w")

test_cases = f.readline()
tc = 1
for i in f:
	max_level, people = i.split(" ")
	max_level = int(max_level)
	peopleCopy = map(int, list(people.strip("\n")))
	friends = 0
	for a in range(1,max_level+1):
		if peopleCopy[a] > 0 and (sum(peopleCopy[:a]) + friends < a):
			friends = friends + (a - (sum(peopleCopy[:a]) + friends))

	output.write("Case #{0}: {1}\n".format(tc, friends))
	tc += 1

f.close()
output.close()
