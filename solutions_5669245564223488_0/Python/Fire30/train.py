for ww in range (0,int(raw_input())):
	length = int(raw_input())
	line  = raw_input().split()
	total = 1
	connected = []
	for y in range(0,len(line)):
		for z in range(0,len(line)):
			if y == z:
				continue
			if line[y][-1] == line[z][0]:
				connected.append((z,y))
			if line[y][0] == line[z][-1]:
				connected.append((y,z))
	real_connected = []
	for i in connected:
  		if i not in real_connected:
			real_connected.append(i)
	connected = real_connected
	real_connected  = []
	index = 0
	for x,y in connected:
		if x or y == index:
			index += 1
		if x or y == index:
			index += 1
	if index < length - 1:
		print 'Case #%d: 0' % (ww+1)
		continue
	for x,y in connected:
		letter_con = 0
		for a,b in connected:
			if x == b and ((a,b),(y,z)) not in real_connected:
				letter_con += 1
				real_connected.append(((x,y),y,z))
			if y == a and ((a,b),(y,z)) not in real_connected:
				letter_con += 1
				real_connected.append(((x,y),y,z))
		if letter_con == 0:
			total * 2
		else:
		 total *= letter_con
	total = total % 1000000007
	print 'Case #%d: %d' % (ww+1,total)
