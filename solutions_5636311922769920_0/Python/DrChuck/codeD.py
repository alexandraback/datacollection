# codejam D

T = int(raw_input())
for i in range(T):
	line = raw_input()
	line = line.split()
	k, c, s = int(line[0]), int(line[1]), int(line[2]) 
	#print k, c, s
	stu = 0
	tile = 0
	pos = []
	print "Case #"+str(i+1)+": ",
	while stu <= s and tile < k:
		num = tile
		for i in range(tile + 1, min(k, tile+c) ):
			num = num * k + i
		#print tile, num
		pos.append(num)
		stu += 1
		tile += min(c,k)
	if tile < k-1 or stu > s:
		print "IMPOSSIBLE"
	else:
		print " ".join([str(i+1) for i in pos])