#usr/bin/python
from __future__ import division
import sys

fin = open(sys.argv[1], "r")
fout = open("C.out", "w")
     

T = int(fin.readline())
for ii in xrange(T):
	n = int(fin.readline())
	friends = map(lambda x: int(x)-1, fin.readline().split(' '))
	circ_len = []
	cycle_end = []
	len_two = []
	all_used = []
	for i in range(len(friends)):
		#print 'new'
		start = i
		used = [i]
		new_friend = friends[i]
		while used.count(new_friend) == 0:
			used.append(new_friend)
			#print new_friend, friends[new_friend]
			new_friend = friends[new_friend]
		if used.count(new_friend) == 1:
			all_used.append(used)
			print i, used, new_friend
			if used[-2] == new_friend:
				cycle_end.append( used[-2:])
				circ_len.append(len(used))
				len_two.append([0,0])
			else:				
				cycle_end.append([0,0])
				if len(used) - used.index(new_friend) > used.index(new_friend):
					circ_len.append( len(used) - used.index(new_friend))
				else:
					circ_len.append( used.index(new_friend))	
				if len(used)>=2:
					len_two.append(used[-2:])
	 			else:
	 				len_two.append([0,0])			
	print circ_len, cycle_end	
	for i in range(len(cycle_end)):
		for j in range(len(cycle_end)):
			if (cycle_end[i] != [0,0]) and (cycle_end[i][0] == cycle_end[j][1]) and (cycle_end[i][1] == cycle_end[j][0]) and (len(all_used[i]) > 2) and (len(all_used[j]) >2) and(all_used[j][-3] != all_used[i][-3]):
				circ_len.append(circ_len[i] + circ_len[j] - 2)
				print 'here', i, j
	for i in range(len(len_two)):
		for j in range(len(len_two)):
			if (cycle_end[i] != [0,0]) and (len_two[j] != [0,0]) and cycle_end[i][1] == len_two[j][1] and cycle_end[i][0] != len_two[j][0] and len_two[j][0] != i:
				#print 'here', cycle_end[i], len_two[j], i, j
				circ_len.append(circ_len[i] + circ_len[j] - 1)

	sol = max(circ_len)	
	if sol > len(friends):		
		sol = len(friends)

	#sol = 0

	fout.write("Case #" + str(ii+1) + ": " + str(sol) + "\n")