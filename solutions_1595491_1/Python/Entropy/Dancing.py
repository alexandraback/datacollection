data = [ [int(a) for a in i.split(" ")] for i in open("B-large.in","rU").read()[:-1].split("\n")]
count = 0
for line in data[1:]:
	count += 1
	supps = line[1]
	score = line[2]
	maxes = 0
	nonsuptot = (score*3)-2
	suptot = (score*3)-4
	if suptot < 0:
		suptot = 1
	for i in range(3,(len(line))):
		if line[i] >= nonsuptot:
			maxes += 1
			continue
		if (line[i] >= suptot) and (supps > 0):
			maxes += 1
			supps -= 1
	if score == 0:
		maxes = line[0]
	print ("Case #"+str(count)+":", maxes)
		
			




