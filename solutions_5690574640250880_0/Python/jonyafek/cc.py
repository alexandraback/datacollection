#!/usr/bin/python

import sys
import itertools


in_f = open(sys.argv[1], "rt")

in_lines = in_f.readlines()

num_tests = int(in_lines[0])

in_lines = in_lines[1:]

out = ""

for i in xrange(num_tests):
	[param_r,param_c,param_m] = [int(n) for n in in_lines[0].split()]
	in_lines = in_lines[1:]

	#print "Test: " + str(i+1)
	#print param_r
	#print param_c
	#print param_m

	free_spots = param_r*param_c - param_m

	if (free_spots == 1):
		out += "Case #"+str(i+1)+":\n"
		out += "c" + "*"*(param_c-1)+"\n"
		out += ("*"*param_c + "\n")*(param_r-1)
		continue

	if (param_r == 1):
		out += "Case #"+str(i+1)+":\n"
		out += "c" + (param_c-param_m-1)*"." + param_m*"*"+"\n"
		continue

	if (param_c == 1):
		out += "Case #"+str(i+1)+":\n"
		out += "c\n" + (param_r-param_m-1)*".\n" + param_m*"*\n"
		continue

	if (free_spots == 3 or free_spots == 2 or free_spots == 5 or free_spots == 7):
		out += "Case #"+str(i+1)+":\n"
		out += "Impossible\n"
		continue

	if (param_r == 2):
		out += "Case #"+str(i+1)+":\n"
		if (free_spots%2==0):
			free_c = free_spots/2
			out += "c" + (free_c-1)*"." + (param_c-free_c)*"*"+"\n"
			out += (free_c)*"." + (param_c-free_c)*"*"+"\n"
		else:
			out += "Impossible\n"
		continue

	if (param_c == 2):
		out += "Case #"+str(i+1)+":\n"
		if (free_spots%2==0):
			free_r = free_spots/2
			out += "c.\n"
			out += "..\n"*(free_r - 1)
			out += "**\n"*(param_r - free_r)
		else:
			out += "Impossible\n"
		continue

	if (free_spots == 4):
		out += "Case #"+str(i+1)+":\n"
		out += "c." + "*"*(param_c-2) + "\n"
		out += ".." + "*"*(param_c-2) + "\n"
		out += ("*"*(param_c) + "\n")*(param_r-2)
		continue

	if (free_spots == 6):
		out += "Case #"+str(i+1)+":\n"
		out += "c.." + "*"*(param_c-3) + "\n"
		out += "..." + "*"*(param_c-3) + "\n"
		out += ("*"*(param_c) + "\n")*(param_r-2)
		continue

	if (free_spots/3 >= param_r):
		out += "Case #"+str(i+1)+":\n"
		free_spots -= 3*param_r
		num_free_c = 3
		num_free_c += free_spots/param_r
		free_spots -= (param_r*(num_free_c-3))
		remove_from_last_c = False
		if (free_spots == 1):
			remove_from_last_c = True
		for j in xrange(param_r):
			if (j==0):
				out += "c"
			else:
				out += "."
			if (j < free_spots):
				out += "."*(num_free_c) + "*"*(param_c-num_free_c-1) + "\n"
			elif (j == free_spots and remove_from_last_c):
				out += "."*(num_free_c) + "*"*(param_c-num_free_c-1) + "\n"
			elif (j == param_r-1 and remove_from_last_c):
				out += "."*(num_free_c-2) + "*"*(param_c-num_free_c+1) + "\n"
			else:
				out += "."*(num_free_c-1) + "*"*(param_c-num_free_c) + "\n"
		continue
	else:
		out += "Case #"+str(i+1)+":\n"
		num_rows_threes = free_spots/3
		free_spots -= num_rows_threes*3
		remove_from_last_r = False
		if (free_spots == 1):
			remove_from_last_r = True
		for j in xrange(param_r):
			if (j==0):
				out += "c"
			elif (j < num_rows_threes or (j==num_rows_threes and free_spots > 0)):
				out += "."
			else:
				out += "*"

			if (j == num_rows_threes-1 and remove_from_last_r):
				out += "." + "*"*(param_c-2) + "\n"
			elif (j < num_rows_threes):
				out += ".." + "*"*(param_c-3) + "\n"
			elif (j == num_rows_threes and remove_from_last_r):
				out += "."*(free_spots) + "*"*(param_c-free_spots-1) + "\n"
			elif (j == num_rows_threes and free_spots>0):
				out += "."*(free_spots-1) + "*"*(param_c-free_spots) + "\n"
			else:
				out += "*"*(param_c-1) + "\n"
		continue


print out
