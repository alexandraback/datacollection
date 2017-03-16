# Author: Davin Choo
# Email: cxjdavin@gmail.com

# Warning: Very messy code! >.<

# Observe that:
# i*j*k = -1
# Given any element y, y^4 = 1
# Given any element y (except 1 or -1), y^2 = -1 = i*j*k

# Approach:
# Since multiplication is associative, just check that:
# (a) Multiply from left (indices "start to 4L"), we can obtain 'i'
# (b) Multiply from right (indices "end to end-4L"), we can obtain 'k'
#     (Ensure we do not cross minimum index needed in part a)
# (c) Let Z = multiplication of 1 pass from indices "start to L"
#	  If x = 1, check that Z = -1 = i*j*k
#	  If x > 1 and x % 4 == 1, check that Z = -1 = i*j*k
#	  If x > 1 and x % 4 == 2, check that Z != 1 and Z != -1
#	  If x > 1 and x % 4 == 3, check that Z = -1 = i*j*k

# Look at bottom commented code on how mult is generated.
# Usage: x*y = mult[x][y]
mult = [[0, 1, 2, 3, 4, 5, 6, 7], [1, 4, 3, 6, 5, 0, 7, 2], [2, 7, 4, 1, 6, 3, 0, 5], [3, 2, 5, 4, 7, 6, 1, 0], [4, 5, 6, 7, 0, 1, 2, 3], [5, 0, 7, 2, 1, 4, 3, 6], [6, 3, 0, 5, 2, 7, 4, 1], [7, 6, 1, 0, 3, 2, 5, 4]]
letter_to_index = {'1': 0, 'i': 1, 'j': 2, 'k': 3, '-1': 4, '-i': 5, '-j': 6, '-k': 7}
index_to_letter = dict(map(reversed, letter_to_index.iteritems()))

T = int(raw_input())

for i in xrange(0, T):
	temp = raw_input().split()
	L = int(temp[0])
	X = int(temp[1])
	lst = raw_input()

	output = "NO"
	if L*X >= 3:
		firstL, i_index, k_index = -1, -1, -1
		seen_i, seen_k = False, False
		from_right = 1

		z = letter_to_index[lst[0]]
		if z == 1: # We hit 'i'
			i_index = 0
			seen_i = True

		for index in xrange(1, L):
			letter = letter_to_index[lst[index]]
			z = mult[z][letter]
			
			if not seen_i and z == 1: # We hit 'i'
				i_index = index
				seen_i = True

		firstL = z

		z = letter_to_index[lst[L-1]]
		if z == 3: # We hit 'k'
			k_index = L*X - from_right
			seen_k = True

		for index in xrange(L-2, -1, -1):
			letter = letter_to_index[lst[index]]
			z = mult[letter][z]
			from_right += 1

			if not seen_k and z == 3: # We hit 'k'
				k_index = L*X - from_right
				seen_k = True

		if X > 1:
			# Hunt for "i" from the left
			z = firstL
			for passes in xrange(1, min(X,4)):
				if seen_i:
					break

				for index in xrange(0, L):
					letter = letter_to_index[lst[index]]
					z = mult[z][letter]
					
					if not seen_i and z == 1: # We hit 'i'
						i_index = passes * L + index
						seen_i = True

			# Hunt for "k" from the right
			z = firstL
			for passes in xrange(1, min(X,4)):
				if seen_k:
					break

				for index in xrange(L-1, 0, -1):
					letter = letter_to_index[lst[index]]
					z = mult[letter][z]
					from_right += 1

					if not seen_k and z == 3: # We hit 'k'
						k_index = L*X - from_right
						seen_k = True

		# CHECK!
		# print "-----"
		# print X, firstL, seen_i, seen_k, i_index, k_index
		if (seen_i and seen_k and i_index < k_index):
			if (X % 4 == 1 and firstL == 4): # firstL = i*j*k = '-1'
				output = "YES"
			if (X % 4 == 2 and firstL != 0 and firstL != 4): # firstL != '1' and firstL != '-1'
				output = "YES"
			if (X % 4 == 3 and firstL == 4): # firstL = i*j*k = '-1'
				output = "YES"

	print "Case #" + str(i+1) + ": " + str(output)

###################################################
# THE CODE BELOW IS USED TO GENERATE mult OFFLINE #
###################################################

# # Usage: x*y = mult[x][y]
# # For negated version, just flip sign
# # column  =  1,  i,  j,  k, -1, -i, -j, -k
# # row =  1:  1,  i,  j,  k, -1, -i, -j, -k
# # row =  i:  i, -1,  k, -j, -i,  1, -k,  j
# # row =  j:  j, -k, -1,  i, -j,  k,  1, -i
# # row =  k:  k,  j, -i, -1, -k, -j,  i,  1
# # row = -1: -1, -i, -j, -k,  1,  i,  j,  k
# # row = -i: -i,  1, -k,  j,  i, -1,  k, -j
# # row = -j: -j,  k,  1, -i,  j, -k, -1,  i
# # row = -k: -k, -j,  i,  1,  k,  j, -i, -1

# dicti = {'1': 'i', 'i': '-1', 'j': 'k' , 'k': '-j'}
# dictj = {'1': 'j', 'i': '-k', 'j': '-1', 'k': 'i' }
# dictk = {'1': 'k', 'i': 'j' , 'j': '-i', 'k': '-1'}

# # x and y are letters
# # returns x*y as a letter
# def f(x, y):
# 	flip = 0
# 	if x[0] == '-':
# 		x = x[1]
# 		flip += 1
# 	if y[0] == '-':
# 		y = y[1]
# 		flip += 1
# 	flip = flip % 2

# 	if x == '1':
# 		output = y
# 	elif x == 'i':
# 		output = dicti[y]
# 	elif x == 'j':
# 		output = dictj[y]
# 	elif x == 'k':
# 		output = dictk[y]
# 	else:
# 		print "ERROR!"

# 	if flip == 1:
# 		if output[0] == '-':
# 			output = output[1:]
# 		else:
# 			output = '-' + output
# 	return output

# def gen_table():
# 	table = [[],[],[],[],[],[],[],[]]
# 	to_run = ['1','i','j','k','-1','-i','-j','-k']
# 	for x in to_run:
# 		for y in to_run:
# 			a = letter_to_index[x]
# 			b = letter_to_index[y]
# 			c = f(x,y)
# 			table[a] += [letter_to_index[c]]
# 	print table

# gen_table()