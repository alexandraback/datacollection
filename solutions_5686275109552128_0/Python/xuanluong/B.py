def can_do(move_time, eat_time, height_dict):
	while move_time > 0:
		for height in height_dict.keys():
			height_dict[height] -= 1
			if height_dict[height] == 0:
				del height_dict[height]
			height -= eat_time			
			if height > eat_time:
				if height not in height_dict:
					height_dict[height] = 0
				height_dict[height] += 1
			break
		move_time -= 1
	if len(height_dict.keys()) > 0:
		return False
	return True

T = int(raw_input())
for test in xrange(T):
	D = int(raw_input())
	Ps = [int(i) for i in raw_input().split(" ")]
	height_dict = {}
	total_height = 0
	for P in Ps:
		if P not in height_dict:
			height_dict[P] = 0
		height_dict[P] += 1
		total_height += P
	min_time = max(Ps)
	done = False
	for time in xrange(1, min_time):
		for move_time in xrange(time):
			eat_time = time - move_time
			if can_do(move_time, eat_time, { k:height_dict[k] for k in height_dict.keys() if k > eat_time }):
				min_time = time
				done = True
				break
		if done:
			break
	print "Case #%d: %d" % (test + 1, min_time)
