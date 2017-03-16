def solve(case):
	case = case.split(' ')
	moves = ''
	
	x = int(case[0])
	y = int(case[1])
	
	dist = 1
	posx = 0
	posy = 0
	
	if posx < x:
		while posx < x:
			posx += dist
			dist += 1
			moves += 'E'
		if posx > x:
			while posx != x:
				posx += dist
				dist += 1
				posx -= dist
				dist += 1
				moves += 'EW'
				
	elif posx > x:
		while posx > x:
			posx -= dist
			dist += 1
			moves += 'W'
		if posx < x:
			while posx != x:
				posx -= dist
				dist += 1
				posx += dist
				dist += 1
				moves += 'WE'
				
	if posy < y:
		while posy < y:
			posy += dist
			dist += 1
			moves += 'N'
		if posy > y:
			while posy != y:
				posy += dist
				dist += 1
				posy -= dist
				dist += 1
				moves += 'NS'
				
	elif posy > y:
		while posy > y:
			posy -= dist
			dist += 1
			moves += 'S'
		if posy < y:
			while posy != y:
				posy -= dist
				dist += 1
				posy += dist
				dist += 1
				moves += 'SN'
				
	return moves
	
file = open('B-small-attempt1.in','r')
lines = file.readlines()
for i in range(len(lines)):
	lines[i] = lines[i].strip()
file.close()

linesout = []
toout = ''
line = 1
while line < len(lines):
	toout = solve(lines[line])
	linesout.append('Case #' + str(len(linesout) + 1) + ': ' + toout + '\n')
	toout = ''
	line = line+1

linesout[-1] = linesout[-1][:-1]
file = open('out','w')
file.writelines(linesout)