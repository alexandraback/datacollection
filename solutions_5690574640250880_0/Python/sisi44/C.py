deja = []
res = 0

def decide(R, C, NM, v1, v2):
	global deja
	global res
	#print deja, res, 'begin'
	new = False
	if deja[v1][v2] == 2:
		new = True
		res += 1
	deja[v1][v2] = 0
	change = []
	for i in [v1-1, v1, v1+1]:
		for j in [v2-1, v2, v2+1]:
			if i != v1 or j != v2:
				if i >= 0 and i < R and j >=0 and j < C:
					if deja[i][j] == 2:
						deja[i][j] = 1
						change.append((i,j))
						res += 1
	#print deja, res
	if res == NM: 
		return True
	elif res > NM:
		for (i,j) in change:
			deja[i][j] = 2
			res -= 1
		if new:
			deja[v1][v2] = 2
			res -= 1
		else:
			deja[v1][v2] = 1
		return False
	else:
		for i in [v1-1, v1, v1+1]:
			for j in [v2-1, v2, v2+1]:
				if i != v1 or j != v2:
					if i >= 0 and i < R and j >=0 and j < C:
						if (i-v1)*(j-v2) == 0 and deja[i][j] != 0:
							if decide(R, C, NM, i, j):
								return True
		# put back
	#	print change
		for (i,j) in change:
			deja[i][j] = 2
			res -= 1
		if new:
			deja[v1][v2] = 2
			res -= 1
		else:
			deja[v1][v2] = 1
	#	print deja, res, 'back'
		return False 



def decideFinal(R, C, NM):
	global deja
	global res
	deja = [[2 for j in range(C)] for i in range(R)]
	res = 0
	if decide(R, C, NM, 0, 0):
		return deja
	if 1 < R:
		if decide(R, C, NM, 1, 0):
			return deja
		if 1 < C:
			if decide(R, C, NM, 1, 1):
				return deja
	if 1 < C:
		if decide(R, C, NM, 0, 1):
			return deja
	return []


def solve():
	#f = open("in.txt", 'r')
	f = open("C-small-attempt4.in.txt", 'r')
	T = int(f.readline())
	for t in range(T):
		[R, C, M] = [int(k) for k in f.readline().split()]
		deja = decideFinal(R, C, R*C-M)
		print "Case #%i:" % (t+1) 
		if deja == []:
			if R*C-M != 1:
				print "Impossible"
			else:
				for i in range(R):
					s = ""
					for j in range(C):
						if i == 0 and j == 0:
							s += 'c'
						else:
							s += '*'

					print s
					
		else:
			findZero = False
			for i in range(R):
				s = ""
				for j in range(C):
					if deja[i][j] == 2:
						s += '*'
					else:
						if not findZero and deja[i][j] == 0:
							findZero = True
							s += 'c'
						else:
							s += '.'
				print s


solve()