import sys

if __name__=='__main__':
	f = open(sys.argv[1], 'r')
	T = int(f.readline()[:-1])
	for case_no in range(1, T + 1):
		R = map(int, f.readline()[:-1].split(' '))
		N = R[0]
		S = R[1]
		p = R[2]
		G = R[3:]

		y = 0
		for g in G:
			if g%3 == 0:
				if g/3 >= p:
					y += 1
				elif S > 0 and g > 0:
					if g/3+1 >= p:
						y += 1
						S -= 1
			elif g%3 == 1:
				if (g-g%3)/3+1 >= p:
					y+=1
			elif g%3 == 2:
				if (g-g%3)/3+1 >= p:
					y += 1
				elif S > 0:
					if (g-g%3)/3+2 >= p:
						y += 1
						S -= 1
		print "Case #%s: %s" % (case_no, y)
	
