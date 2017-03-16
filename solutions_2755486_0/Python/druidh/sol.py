import sys
import array

def read_ints():
	return map(int, sys.stdin.readline().split())
#	return [int(x) for x in sys.stdin.readline().split()]

(T,) = read_ints()
for case in range(1, T + 1):
	(N, ) = read_ints()
	dias_a = []
	tribes = []
	for i in xrange(N):
		d, n, w, e, s, dd, dp, ds = read_ints()
		dias = [x for x in xrange(d, d+n*dd, dd)]
		strength = []
		west = []
		east = []
		if (ds == 0):
			strength = [s] * n
		else:
			strength = [x for x in xrange(s, s+n*ds, ds)]
		if (dp == 0):
			west = [w] * n
			east = [e] * n
		else:
			west = [x for x in xrange(w, w+n*dp, dp)]
			east = [x for x in xrange(e, e+n*dp, dp)]
#		print dias
#		print strength
#		print west
#		print east

		tribe = {}
		for i in xrange(n):
			tribe[dias[i]] = [strength[i], west[i], east[i]]

		tribes.append(tribe)

		dias_a.extend(dias)
		dias_a = list(set(dias_a))

	dias_a.sort()

	ans = 0
#	wall = array.array('L', [0]*500)
	wall = {}
	for d in dias_a:
		new_wall = wall.copy()
		# new_wall = wall[:]
#		print ' * ' + str(d)
		for tribe in tribes:
			rompe = 0
			if (d in tribe):
				s, w, e = tribe[d]
				for x in xrange(w, e):
					if (x not in wall):
						new_wall[x] = s
						rompe = 1
					else:
						if (wall[x] < s):
							rompe = 1
							if (new_wall[x] < s):
								new_wall[x] = s
			ans += rompe
#				pwall = wall[w:e]
#				if (s > min(wall[w:e])):
#					ans += 1
#					for i in xrange(w, e):
#						new_wall[i] = s

#				print w, e, s
#				print wall[w:(e+1)]
#				print ans

#		wall = new_wall[:]
		wall = new_wall.copy()

#	print dias_a


	print "Case #%d: %s" % (case, ans)
	

