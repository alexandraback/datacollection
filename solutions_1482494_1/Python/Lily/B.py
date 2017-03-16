def stars(T, AB):
	#T = "2"
	#AB = ["0 1", "0 2"]

	ab = []
	for s in AB:
		sp = s.split(' ')
		ab.append((int(sp[0]), int(sp[1])))

	# sort by 2-star difficulty
	# if we're stuck and need to do 1-star for a level, we want to do it on a level that's more difficult to get 2-star
	ab.sort(key=lambda x:x[1]*-1)
		
	t = int(T)	# number of levels

	s = 0 	# current number of stars
	l = 0	# number of levels played

	go = True
	solved = False
	while go:
		go = False
		for p in ab:
			if(p[1] <= s):
				go = True
				if(p[0] == t*3):
					s += 1
				else:
					s += 2
				l += 1
				ab.remove(p)
		if not go:
			for p in ab:
				if(p[0] <= s):
					go = True
					s += 1
					l += 1
					ab.remove(p)
					ab.append((t*3,p[1]))		#whatever, hack to prevent doing level 1 twice
					break
		if len(ab) == 0:
			go = False
			solved = True

	if solved:
		return l
	else:
		return "Too Bad"
		
f = open('B-large.in', 'r')
T = int(f.readline())
for i in range(T):
	N = f.readline()
	AB = []
	for j in range(int(N)):
		AB.append(f.readline())
	print "Case #{}: {}".format(i+1, stars(N,AB))