T = int(raw_input())

def doprob():
	N = int(raw_input())
	array = [None]
	line = raw_input().split()
	for i in line:
		array.append(int(i))
	doubles = [x for x in xrange(1, N+1) if array[array[x]] == x]
	outcomes = {}

	for i in xrange(1, N+1):
		start = i
		OK = 0
		for j in xrange(N+1):
			new = array[start]
#			print i, new
			if array[new] == start or new == i:
				OK = 1
				break
			start = new
		if OK == 0:
			outcomes[i] = (None, 0, "forb")

#	print outcomes
	def populate(i, start, length):
		if length > N+5:
			outcomes[start] = (None, 0, "forb")
			populate(i, i, 0)
#		print i, start, length
		if i in outcomes:
			return
		if array[array[i]] == i:
			outcomes[i] = (i, 0, "pair")
			outcomes[array[i]] = (array[i], 0, "pair")
			return
		if array[i] not in outcomes:
			populate(array[i], start, length+1)


		if i == start and length > 0:
			outcomes[i] = (start, length, "loop")
			return
#		if 

		if outcomes[array[i]][2][:4] == "forb":
			outcomes[i] = (None, 0, "forb")
			return
		outcomes[i] = (outcomes[array[i]][0], outcomes[array[i]][1]+1, outcomes[array[i]][2]+"ex")

	for i in xrange(1, N+1):
		populate(i, i, 0)

#	print array
#	print 
#	print outcomes
#	print

	lendict = dict([(x, 0) for x in doubles])
	result = 0
	for i in outcomes:
		fff = outcomes[i]
		if fff[2] == "loopex":
			result = max(result, fff[1]-1)
		if len(fff[2]) >=6 and fff[2][:6] == "pairex":
			lendict[fff[0]] = max(lendict[fff[0]], fff[1])

#	print result
#	print lendict
#	print
	proposal = 0
	for i in doubles:
#		print i
		proposal += 1 + lendict[i]
	return max(result, proposal)

for qq in xrange(T):
	print "Case #" + str(qq+1) + ": " + str(doprob())