T = int(raw_input())
for case in range(1, T + 1):
	n = int(raw_input())
	data = [0] * 2
	data[0] = map(float, raw_input().split())
	data[1] = map(float, raw_input().split())

	data[0].sort()
	data[1].sort()

	deceit = 0
	naomi = 0
	for ken in range(0, n):
		while naomi < n and data[0][naomi] < data[1][ken]:
			naomi += 1

		if naomi < n:
			deceit += 1
			naomi += 1
	
	normal = 0
	for naomi in range(0, n):
		found = False
		for ken in range(0, n):
			if data[0][naomi] < data[1][ken]:
				found = True
				data[1][ken] = -1.0
				break

		if found == False:
			normal += 1
			for ken in range(0, n):
				if data[1][ken] != -1.0:
					data[1][ken] = -1.0
					break
	
	print "Case #" + str(case) + ":", deceit, normal
