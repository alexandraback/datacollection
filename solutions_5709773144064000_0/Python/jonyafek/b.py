#!/usr/bin/python

import sys

in_f = open(sys.argv[1], "rt")

in_lines = in_f.readlines()

num_tests = int(in_lines[0])

in_lines = in_lines[1:]

out = ""

for i in xrange(num_tests):
	[param_c,param_f,param_x] = [float(n) for n in in_lines[0].split()]
	in_lines = in_lines[1:]
	#print param_c
	#print param_f
	#print param_x

	time_so_far = 0.0
	production_power = 2.0
	last_current_time = 0.0
	while (True):
		current_time = time_so_far + (param_x / production_power)
		if (last_current_time == 0):
			last_current_time = current_time
		elif (last_current_time < current_time):
			out += "Case #"+str(i+1)+": "+str(last_current_time)+"\n"
			break

		time_so_far += param_c / production_power
		production_power += param_f
		last_current_time = current_time

		#print "-----------------"
		#print current_time
		#print last_current_time
		#print production_power
		#print time_so_far
		#print "-----------------"

print out

