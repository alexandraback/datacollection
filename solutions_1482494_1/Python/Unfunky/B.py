#!/usr/bin/python -u

import sys,re

if len(sys.argv) != 2:
  print "usage: " + sys.argv[0] + " infile"
  sys.exit()
infile = open(sys.argv[1], 'r')

debugprint = 0

def debug(str, lvl=5):
  if debugprint > lvl: print "[DEBUG]", str

def handleonecase(line1):
	#TODO
	N = int(line1[0])
	num_stars = 0
	num_levels_played = 0
	l1_beaten = set()
	l2_beaten = set()
	l1_tuples = []
	l1_playable_tuples = []
	l2_tuples = []
	for i in range(0, N):
		levelinfo = infile.readline().strip().split()
		onestarreq = int(levelinfo[0])
		twostarreq = int(levelinfo[1])
		l1_tuples.append((i, onestarreq, twostarreq))
		l2_tuples.append((i, onestarreq, twostarreq))
	l1_tuples.sort(key=lambda x: x[1])
	l2_tuples.sort(key=lambda x: x[2])
	while True:
		if(len(l2_tuples) == 0):
			return num_levels_played
		if(l2_tuples[0][2] <= num_stars):
			level_id = l2_tuples[0][0]
			if(level_id in l1_beaten):
				num_stars += 1
			else:
				num_stars += 2
			num_levels_played += 1
			l1_beaten.add(level_id)
			l2_beaten.add(level_id)
			l2_tuples.pop(0)
			continue
		# figure out which level ones are playable
		while(len(l1_tuples) > 0 and l1_tuples[0][1] <= num_stars):
			l1_playable_tuples.append(l1_tuples.pop(0))
		l1_playable_tuples.sort(key=lambda x: -x[2]) # by highest l2
		if(len(l1_playable_tuples) == 0):
			return "Too Bad"
		level_id = l1_playable_tuples[0][0]
		if(level_id in l1_beaten):
			l1_playable_tuples.pop(0)
			continue
		num_stars += 1
		num_levels_played += 1
		l1_beaten.add(level_id)
		l1_playable_tuples.pop(0)
		continue
		return "Too Bad"
	return "This shouldn't happen"

maxcases = 0
casenum = 0

line = infile.readline().strip()
maxcases = int(line)
while line:
  casenum = casenum + 1
  if casenum > maxcases: break
  line1 = infile.readline().strip().split()
  result = handleonecase(line1)
  print "Case #" + str(casenum) + ": " + str(result)




