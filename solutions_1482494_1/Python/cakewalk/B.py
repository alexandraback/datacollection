T = raw_input()
T = int(T)

for t in range(1, T+1):
	N = raw_input()
	N = int(N)
	levels = []
	for i in range(1,N+1):
		tmp = raw_input()
		tmp = map(int,tmp.split(' '))
		levels.append((tmp[1], 2, i,tmp[0]))
		levels.append((tmp[0], 1, i, tmp[1]))

	levelsStatus = [0]*N

	levels.sort()
	levels.reverse()
#	print levels
	stars =  0
	count = 0
	flag = 0
	while(levels!=[] and flag == 0):	
		if levels[len(levels)-1][0] > stars:
			print 'Case #' + str(t) + ': ' + 'Too Bad'
			flag=1
		else:
			choices = filter(lambda a: a[0]<=stars, levels)
			choices.sort(key = lambda a: (a[1]-levelsStatus[a[2]-1], a[1],a[3]))
			choiceMade = choices[len(choices)-1]
			stars += choiceMade[1] - levelsStatus[choiceMade[2]-1]
			levelsStatus[choiceMade[2]-1] = choiceMade[1]
			if choiceMade[1] == 2:
				levels =filter(lambda a: a[2]!=choiceMade[2], levels)
			else:
				levels.remove(choiceMade)
#			print choiceMade
			count += 1
	if levels==[]:
		print 'Case #' + str(t) + ': ' + str(count)

