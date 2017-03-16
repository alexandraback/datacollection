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
	elif x == 5:
		# 12 fundamentally different ominoes:
		#                                                     *
		#                *      *       **     **    * *      *
		# (a)***** (b)**** (c)**** (d)***  (e)*** (f)*** (g)***
		#
		#      *      *      *     *        *
		#    ***    ***    ***    ***      **
		# (h)  * (i) *  (j)*   (k) *  (l) **
        # If rows or columns less than 3, choose (k), R wins
		# Since 5 is prime, either rows or columns is multiple of 5
		# (a) never wins for R
		# (b) and (e) combine with themselves to 5 by 2 block
		# (c), (e), (f) make 5 by 3 block
		# (d), (e), (f) make 5 by 3 block
		# (e), (e), (g) make 5 by 3 block
		# (e), (e), (h) make 5 by 3 block
		# (e), (f), (i) make 5 by 3 block
		# (f), (f), (k) make 5 by 3 block
		# On 5 by 3, choose l, R wins
        # 10 by 3 can be made with l, so can 5 by 4
		# So in all other cases, G wins
		if min(r, c) <= 2 or (min(r, c) == 3 and max(r, c) == 5):
			winner = 'R'
		else:
			winner = 'G'
	elif x == 6:
		# (a)******
		#
		#        *        *       *  
		# (b)***** (c) ***** (d)*****
		#
		#                                                *      *
		#       **      **     * *    *  *     **        *      *
		# (e)****  (f)**** (g)**** (h)**** (i)**** (j)**** (k)****
        #
		#       *       *       *       *      *       *
        #    ****    ****    ****    ****    ****    ****
		# (l)   * (m)  *  (n) *   (o)*    (p)  *  (q) *  
		#
		#                                       *      *       *     *
		#      ***     ***    * **    ***      **      **     **     **
		# (r)***   (s)***  (t)***  (u)*** (v)***  (w)***  (x)*** (y)***
		#
		#      *      **     **     **      **      **      **     **
		#    * *      *       *     *     ***     ***     ***     ***
		# (z)*** (A)***  (B)*** (C)*** (D)  *  (E) *   (F)*    (G) *
		#
		#     **    * *      **
		#    ***    ***     **
		# (H)*   (I) *  (J)**
		winner = 'R' if min(r, c) <= 3 else 'G'
	else:
		# x >= 7, choose omino with enclosed hole
		winner = 'R'

	print('Case #%d: %s' % (icase, 'GABRIEL' if winner == 'G' else 'RICHARD'))
