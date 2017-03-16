#!/usr/bin/python3

t = int(input())
for icase in range(1, t+1):
	x, r, c = map(int, input().split())
	if (r*c)%x != 0:
		# will never match
		winner = 'R'
	elif x <= 2:
		# will always match
		winner = 'G'
	elif x == 3:
		# if field is n by 1, R chooses hook omino. Otherwise,
		# field length is multiple of 3 in at least one direction,
		# and at least 2 in the other. G can combine two hooks to
		# make a 3 by 2 block, and can fill the rest up with
		# 3 by 1 ominos.
		winner = 'R' if r == 1 or c == 1 else 'G'
	elif x == 4:
		# 4 fundamentally different start ominos:
		#              *     *     **
		# (a)**** (b)*** (c)*** (d)**
		# On n by one field, choose anything but (a), R wins
		# On n by 2 field, choose (c), R wins
		# On n by 3 field, either r or c is multiple of 4. (a) and
		# (d) are trivially excluded, and G can make the following
		# 4 by 3 structure:
		# *  ***
		# ** * *
		# * ***
		# which includes both (b) and (c)
		# Larger fields can after that always be filled with 
		# combinations of (a) and (d)
		winner = 'R' if min(r, c) <= 2 else 'G'
	elif x >= 7:
		# choose omino with enclosed hole
		winner = 'R'
	elif x > r and x > c:
		# choose x by 1 omino
		winner = 'R'

	print('Case #%d: %s' % (icase, 'GABRIEL' if winner == 'G' else 'RICHARD'))
