from sys import stdin
import sys
import random
import time

#random.seed(10)

num_cases = int(stdin.readline().rstrip())

for k in range(0, num_cases):
	stdin.readline()
	naomi_blocks = [ float(s) for s in stdin.readline().rstrip().split() ]
	ken_blocks = [ float(s) for s in stdin.readline().rstrip().split() ]
	
	n_naomi_blocks = list(naomi_blocks)
	n_ken_blocks = list(ken_blocks)

	assert len(naomi_blocks) == len(ken_blocks)
	
	print "Case #" + str(k+1) + ":",
	
	naomi_pts = 0
	ken_pts = 0
	
	# play deceitful optimally
	while len(ken_blocks) != 0:
		# get the largest from both naomi and ken
		largest_ken = sorted(ken_blocks,reverse=True)[0]
		largest_naomi = sorted(naomi_blocks,reverse=True)[0]
		# if the largest from naomi is less than the largest from ken,
		# - remove smallest from naomi
		# - remove largest from ken
		# - add one point to ken
		if largest_naomi < largest_ken:
			tmp = sorted(naomi_blocks)[0]
			naomi_blocks.remove(tmp)
			ken_blocks.remove(largest_ken)
			ken_pts += 1
		# if the largest from naomi is greater than the largest from ken,
		# - remove largest from both
		# - +1 pt for naomi
		elif largest_naomi > largest_ken:
			naomi_blocks.remove(largest_naomi)
			ken_blocks.remove(largest_ken)
			naomi_pts += 1	
	
	#print ken_pts
	print naomi_pts,
	
	naomi_pts = 0
	ken_pts = 0

	
	# play war optimally
	while len(n_naomi_blocks) != 0:
		# naomi tells her number, and ken must find the smallest number bigger than that!
		biggest_naomi = sorted(n_naomi_blocks,reverse=True)[0]
		
		ken_tmp = []
		for elem in n_ken_blocks:
			if elem > biggest_naomi:
				ken_tmp.append(elem)
		# this is the smallest number from ken bigger than biggest_naomi
		ken_tmp = sorted(ken_tmp)
		
		if len(ken_tmp) != 0 and ken_tmp[0] > biggest_naomi:
			ken_pts += 1
		else:
			naomi_pts += 1
		n_naomi_blocks.remove(biggest_naomi)
		if len(ken_tmp) != 0:
			n_ken_blocks.remove(ken_tmp[0])
	
	print naomi_pts
	
	#sys.exit(0)