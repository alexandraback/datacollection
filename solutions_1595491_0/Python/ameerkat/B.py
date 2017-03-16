# these have numbers at MOST 2 apart
def gen_trip(n, p):
	flag = False
	trips = []
	for i in range(0,11):
		for j in range(0, 11):
			for k in range(0, 11):
				if i + j + k == n:
					if(max([i,j,k]) - min([i,j,k]) <= 2 and max([i,j,k]) >= p):
						trips.append([i, j, k])
						if(max([i,j,k]) - min([i,j,k]) <= 1):
							flag = True
	return trips, flag

f = open("B-small-attempt0.in")
T = f.readline()
c = 1
for line in f:
	max_g = 0
	i = map(int, line.strip().split())
	N = i[0]
	S = i[1]
	p = i[2]
	t_i = i[3:]
	for t in t_i:
		g = gen_trip(t,p)
		#print g
		if g[0]:
			if g[1]:
				max_g += 1
			elif S > 0:
				max_g += 1
				S -= 1
	print "Case #" + str(c) + ": " + str(max_g)
	c += 1