input = open('small.in', 'r').read()

lines = input.split("\n")

T = int(lines[0])

curr_line = 1

for i in range(0,T):
	
	N = int(lines[curr_line])
	levels = [[0,0] for j in range(0,N)]
	
	curr_line += 1
	for j in range(0,N):
		levels[j] = [int(s) for s in lines[curr_line].split(" ")]
		curr_line += 1	
	
	nb_lvl2_av = N
	steps = 0
	stars = 0
	
	while (nb_lvl2_av > 0):
		steps += 1
				
		lvl2_choice = -1
		# lvl 2 directly
		for j in range(0,len(levels)):
			if lvl2_choice == -1  and levels[j][1] <= stars:
				lvl2_choice = j
				stars += 2
				
				if levels[j][0] == 2*N+1:
					stars -= 1
					
				nb_lvl2_av -= 1
				break
		if lvl2_choice != -1:
			# print "play 2-star level "+str(levels[lvl2_choice])+" -> stars : "+str(stars)
			del(levels[lvl2_choice])
		
		# lvl 1
		lvl1_choice = -1
		corresponding_lvl2 = 0
		if lvl2_choice == -1:
			for j in range(0,len(levels)):
				if levels[j][0] <= stars and levels[j][1] > corresponding_lvl2:
					lvl1_choice = j
					corresponding_lvl2 = levels[j][1]
					stars += 1
		if lvl1_choice != -1:
			# print "play 1-star level "+str(levels[lvl1_choice])+" -> stars : "+str(stars)+" "+str(corresponding_lvl2)
			levels[lvl1_choice][0] = 2*N+1
		
		if (lvl2_choice == -1 and lvl1_choice == -1):
			# print "cant play"
			nb_lvl2_av = -1
	
	if nb_lvl2_av == 0:
		r = str(steps)
	else:
		r = "Too Bad"
	print "Case #"+str(i+1)+": "+r



def stringArrayToVector(arr):
	res = []
	for s in arr:
		res += [int(s)]
	return res