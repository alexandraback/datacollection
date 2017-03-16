#!/usr/bin/python

import sys
import bisect

in_f = open(sys.argv[1], "rt")

in_lines = in_f.readlines()

num_tests = int(in_lines[0])

in_lines = in_lines[1:]

out = ""

for i in xrange(num_tests):
	num_logs = int(in_lines[0])
	in_lines = in_lines[1:]
	naomi_logs = [float(n) for n in in_lines[0].split()]
	naomi_logs.sort()
	in_lines = in_lines[1:]
	ken_logs = [float(n) for n in in_lines[0].split()]
	ken_logs.sort()
	in_lines = in_lines[1:]

	#print "Test: " + str(i+1)
	#print num_logs
	#print naomi_logs
	#print ken_logs

	naomi_logs_normal_war = [n for n in naomi_logs]
	ken_logs_normal_war = [n for n in ken_logs]
	normal_war_naomi_c = 0
	normal_war_ken_c = 0
	for j in xrange(num_logs):
		naomi_choise = naomi_logs_normal_war[num_logs-j-1]
		index =  bisect.bisect_left(ken_logs_normal_war, naomi_choise)
		ken_choise_i = 0
		if index != len(ken_logs_normal_war):
			ken_choise_i = index
			normal_war_ken_c += 1
		else:
			normal_war_naomi_c += 1
		naomi_logs_normal_war.pop(num_logs-j-1)
		ken_logs_normal_war.pop(ken_choise_i)
	
	#print normal_war_naomi_c

	naomi_logs_special_war = [n for n in naomi_logs]
	ken_logs_special_war = [n for n in ken_logs]
	special_war_naomi_c = 0
	special_war_ken_c = 0
	special_used_tells = []
	for j in xrange(num_logs):
		if (naomi_logs_special_war[0] < ken_logs_special_war[0]):
			naomi_tell = ken_logs_special_war[-1]-0.00001
			index_1 = bisect.bisect_left(special_used_tells, naomi_tell)
			index_2 = bisect.bisect_left(ken_logs_special_war, naomi_tell)
			while ( (index_1 != len(special_used_tells) and special_used_tells[index_1] == naomi_tell) or (index_2 != len(ken_logs_special_war) and ken_logs_special_war[index_2] == naomi_tell)):
				naomi_tell -= 0.00001
				index_1 = bisect.bisect_left(special_used_tells, naomi_tell)
				index_2 = bisect.bisect_left(ken_logs_special_war, naomi_tell)

			bisect.insort_left(special_used_tells, naomi_tell)
			ken_choise_i =  bisect.bisect_left(ken_logs_special_war, naomi_tell)
			special_war_ken_c += 1
			naomi_logs_special_war.pop(0)
			ken_logs_special_war.pop(ken_choise_i)
		else:
			naomi_tell = ken_logs_special_war[-1]+0.00001
			index_1 = bisect.bisect_left(special_used_tells, naomi_tell)
			index_2 = bisect.bisect_left(ken_logs_special_war, naomi_tell)
			while ( (index_1 != len(special_used_tells) and special_used_tells[index_1] == naomi_tell) or (index_2 != len(ken_logs_special_war) and ken_logs_special_war[index_2] == naomi_tell)):
				if (naomi_tell==1.0):
					break
				naomi_tell += 0.00001
				index_1 = bisect.bisect_left(special_used_tells, naomi_tell)
				index_2 = bisect.bisect_left(ken_logs_special_war, naomi_tell)

			if naomi_tell == 1.0:
				naomi_tell = ken_logs_special_war[-1]-0.00001
				index_1 = bisect.bisect_left(special_used_tells, naomi_tell)
				index_2 = bisect.bisect_left(ken_logs_special_war, naomi_tell)
				while ( (index_1 != len(special_used_tells) and special_used_tells[index_1] == naomi_tell) or (index_2 != len(ken_logs_special_war) and ken_logs_special_war[index_2] == naomi_tell)):
					naomi_tell -= 0.00001
					index_1 = bisect.bisect_left(special_used_tells, naomi_tell)
					index_2 = bisect.bisect_left(ken_logs_special_war, naomi_tell)

				bisect.insort_left(special_used_tells, naomi_tell)
				ken_choise_i =  bisect.bisect_left(ken_logs_special_war, naomi_tell)
				special_war_ken_c += 1
				naomi_logs_special_war.pop(0)
				ken_logs_special_war.pop(ken_choise_i)

			else:
				bisect.insort_left(special_used_tells, naomi_tell)
				special_war_naomi_c += 1
				naomi_logs_special_war.pop(0)
				ken_logs_special_war.pop(0)
	
	#print special_war_naomi_c



	out += "Case #"+str(i+1)+": " + str(special_war_naomi_c) + " " + str(normal_war_naomi_c) + "\n"


print out

