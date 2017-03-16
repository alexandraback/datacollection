from sys import stdin
import sys

num_cases = int(stdin.readline().rstrip())

for i in range(0, num_cases):
	
	st = stdin.readline().rstrip().split()
	#print st
	
	C = float(st[0])
	F = float(st[1])
	X = float(st[2])
	
	best_time = float('inf')
	

	already_time = 0
	time_to_x = 0
	cps = 2
	
	save = 0
	
	while True:

		# calculate the time it would take to get to X
		time_to_x = X / cps
		
		#print "time to x : " + str(time_to_x)
		#print "time to x + already time : " + str(time_to_x+already_time)
		
		if time_to_x+already_time < best_time:
			best_time = time_to_x+already_time
			#print "best time:  " + str(time_to_x+already_time)
			#print
			save = time_to_x+already_time
		else:
			#print "yes"
			print "Case #" + str(i+1) + ": " + str(save)
			break

			
		already_time = already_time + (C / cps)
		cps = cps + F
		
