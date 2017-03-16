ab = []
ans = 999999
visited = {}
def r(rating, stars, levels=0):
	global ans
	valid = True
	for i,j in stars:
		valid = valid and j
	if valid:
		ans = min(levels, ans)	
	elif not (rating, tuple(map(tuple, stars)), levels) in visited:
		visited[(rating, tuple(map(tuple, stars)), levels)] = True
		for i in xrange(len(ab)):
			if rating >= ab[i][1]:
				if stars[i] == [False, False]:
					stars[i] = [True, True]
					r(rating + 2, stars, levels + 1)
					stars[i] = [False, False]
				elif stars[i] == [True, False]:
					stars[i] = [True, True]
					r(rating + 1, stars, levels + 1)
					stars[i] = [False, False]	
			elif rating >= ab[i][0]:
				if stars[i][0] == False:
					stars[i][0] = True
					r(rating + 1, stars, levels + 1)
					stars[i][0] = False

		
T = int(raw_input())
for t in xrange(1, T + 1):
	n = int(raw_input())
	ab = [map(int, raw_input().split(" ")) for i in xrange(n)]
	ans = 999999
	stars = [[False] * 2 for i in xrange(len(ab))]
	visited = {}
	r(0, stars, 0)
	if ans == 999999:
		ans = "Too Bad"
	print "Case #%d: " % t + str(ans)
