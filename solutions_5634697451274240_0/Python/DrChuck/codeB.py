T = int(raw_input())
for index in range(1, T+1):
	pancakes = raw_input()
	up, down = 0, 0
	for cake in pancakes:
		if cake == '+':
			up, down = up, up + 1
		else:
			up, down = down + 1, down
	print "Case #" + str(index) + ":",up
