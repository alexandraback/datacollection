for case in range(1, int(input())+1):
	S = input()
	current = '+'
	total = 0
	for f in S[::-1]:
		if f != current:
			total += 1
		current = f
	print ("Case #%d: %d" % (case,total))

