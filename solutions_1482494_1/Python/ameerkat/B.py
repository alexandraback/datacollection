def is_complete(nl, l):
	for i in range(nl):
		if l[i][1] == 0:
			return False
	return True

def b(nl, l):
	c = []
	for i in range(nl):
		c.append([0, 0])
	s = 0
	lt = 0
	atdl = True
	while not is_complete(nl, c) and atdl:
		atdl = False
		# try 2 star with no level 1 done
		for i in range(nl):
			if s >= l[i][1] and c[i][0] == 0 and c[i][1] == 0:
				atdl = True
				lt += 1
				c[i] = [1, 1]
				s += 2
				break
		if not atdl:
		# try 2 star with level 1 done
			for i in range(nl):
				if s >= l[i][1] and c[i][1] == 0:
					atdl = True
					lt += 1
					c[i] = [1, 1]
					s += 1
					break
		if not atdl:
			# try 1 star
			min_l2 = -1
			for i in range(nl):
				if s >= l[i][0] and c[i][0] == 0:
					if min_l2 == -1:
						min_l2 = i
					elif l[i][1] > l[min_l2][1]:
						min_l2 = i
			if min_l2 != -1:
				atdl = True
				lt += 1
				c[min_l2] = [1, 0]
				s += 1
		#print c, s
	if is_complete(nl, c):
		return lt
	else:
		return -1

if __name__ == "__main__":
	f = open("B-large.in")
	T = int(f.readline().strip())
	for i in range(T):
		N = int(f.readline().strip())
		l = []
		for j in range(N):
			l.append(map(int, f.readline().strip().split()))
		#print l
		lt = b(N, l)
		if lt >= 0:
			print "Case #" + str(i+1) + ": " + str(lt)
		else:
			print "Case #" + str(i+1) + ": Too Bad"
	f.close()
