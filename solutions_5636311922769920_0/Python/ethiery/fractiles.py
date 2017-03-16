def readyToPrint(a):
	'''
	adds one because python arrays indices start from 0
	but the tile numbers are expected to start from 1
	then convert to string
	'''
	return str(a+1)

for testCase in range(int(input())):
	K, C, S = input().split(' ')
	K, C, S = int(K), int(C), int(S)

	# if the complexity of the artwork is 1 then the only solution 
	# to make sure that the original sequence contains gold 
	# is to check all the tiles of the artwork
	if C == 1:
		if S < K:
			print("Case #{}: IMPOSSIBLE".format(testCase+1))
		else:
			indices = [i for i in range(K)]
			print("Case #{}: {}".format(testCase+1, ' '.join(map(readyToPrint, indices))))

	# Of the complexity is 2 or more, we can do better.
	#
	# By checking one tile of the complexity 2 artwork, we can check
	# 2 tiles of the original sequence :
	# - if the tile a*K+b of the complexity 2 artwork is made of lead, 
	# then the tiles a and b of the original sequences are made of lead.
	# - if the tile a*K+b of the complexity 2 artwork is made of gold, 
	# then one of the tiles a and b of the original sequences is made of gold.
	#
	# Also we can notice that the tile i of the complexity X artwork
	# and the tile (i*k)+(i%k) of the complexity X+1 artwork are made of the
	# same material.
	#
	# In the end, given two tiles a and b of the original sequence, 
	# we can compute which tile of the complexity C artwork we can check
	# to have informations on a and b
	else:
		# You can't check the materials of more than 2 tiles of the
		# original sequence by checking 1 tile of the final artwork, 
		# so S must be >= (k+1)//2 	
		if S < (K+1)//2:
			print("Case #{}: IMPOSSIBLE".format(testCase+1))
		else:
			# originalIndices contains all the indices of all the tiles
			#  we have to check in the original sequence,
			# i.e all the indices.
			# the index 0 is duplicated if needed to have an even number
			# of indices.
			originalIndices = [i for i in range(K)]
			if K%2 == 1:
				originalIndices.append(0)
			
			# complexity2Indices contains all the indices we have
			# to check in the complexity 2 artwork to see if the 
			# original sequence contains gold
			complexity2Indices = []
			for i in range(round(len(originalIndices)/2)):
				index = originalIndices[2*i] * K + originalIndices[2*i+1]
				complexity2Indices.append(index)

			# complexityKIndices contains all the indices we have
			# to check in the complexity k artwork to see if the
			# original sequence contains gold
			complexityKIndices = []
			for i in complexity2Indices:
				index = i
				for j in range(C-2):
					index = (index * K) + (index % K)
				complexityKIndices.append(index)

			print("Case #{}: {}".format(testCase+1, ' '.join(map(readyToPrint, complexityKIndices))))
