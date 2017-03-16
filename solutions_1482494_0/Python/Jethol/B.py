#!/usr/bin/env pypy
import sys, os
# Cases
t = int(sys.stdin.readline())

def all_perms(str):
	if len(str) <=1:
		yield str
	else:
		for perm in all_perms(str[1:]):
			for i in range(len(perm)+1):
				#nb str[0:1] works in both string and list contexts
				yield perm[:i] + str[0:1] + perm[i:]

for i in xrange(t):
	result = 0
	stars = 0
	best = -1
	gamesPlayed = 0
	levels = list()
	n = int(sys.stdin.readline())
	for j in xrange(n):
		levels.append(map(int, sys.stdin.readline().split()))
	levels.sort(key=lambda x: [x[0],-x[1]])

	for p in all_perms(levels):
		while True:
			p = filter(None, p)
			if not p:
				stars = str(gamesPlayed)
				break
			#print str(p) + " " + str(stars)
			found = False
			for k in p:
				try:
					if k[1] <= stars:
						p.remove(k)
						found = True
						stars += 2
						gamesPlayed += 1
						break
				except:
					pass
			if found:
				continue
			for k in p:
				if k[0] <= stars:
					k.pop(0)
					found = True
					stars += 1
					gamesPlayed += 1
					break
			if found:
				continue
			for k in p:
				try:
					if k[1] <= stars:
						k.pop(1)
						found = True
						stars += 1
						gamesPlayed += 1
						break
				except:
					pass
			if not found:
				stars = "Too Bad"
				break
		if stars == "Too Bad":
			break
		else:
			if best == -1 or best > stars:
				best = stars
		stars = best
		
	print "Case #%d: %s" % (i+1, stars)
