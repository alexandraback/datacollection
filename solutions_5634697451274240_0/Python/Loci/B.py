cases = int(raw_input())



for case in range(cases):
	answer = ""
	pancakes = raw_input()


	if pancakes.count("+") == len(pancakes):
		flip = 0
	elif pancakes.count("-") == len(pancakes):
		flip = 1
	else:
		flip = 0

		current = 'boobies'
		for c in pancakes:
			if c != current:
				flip += 1
				current = c

		if pancakes[-1] == '+':
			flip -= 1

		
	answer = str(flip)




	print "Case #" + str(case+1) + ": " + answer