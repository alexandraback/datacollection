def solve(liste):
	solution = [liste[0]]
	for i in range(1,len(liste)):
		if max(liste[i], solution[0]) == solution[0]:
			if solution[0] == liste[i]:
				solution.insert(0,liste[i])
			else:
				solution.append(liste[i])
		else:
			solution.insert(0,liste[i])
		
		
	return "".join(solution)



t = int(raw_input())
for i in xrange(1, t + 1):
	numbers = raw_input()
	print "Case #{}: {}".format(i, solve(list(numbers)))
