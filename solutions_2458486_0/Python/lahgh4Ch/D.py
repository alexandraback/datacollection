def openRecursively(chest, holdingKeys):
	if len(chest) == 1:
		(number, openType, inside) = chest[0]
		if openType in holdingKeys:
			return [number]
		else:
			return 'IMPOSSIBLE'
	
	'''
	branching1
	'''
	allKeys = holdingKeys[:]
	needed = {}
	for i, c in enumerate(chest):
		(number, openType, inside) = c
		allKeys.extend(inside)
		if openType in needed:
			needed[openType] += 1
		else:
			needed[openType] = 1
	having = {}
	for k in allKeys:
		if k in having:
			having[k] += 1
		else:
			having[k] = 1
	for k in needed:
		if k not in having:
			return 'IMPOSSIBLE'
		if having[k] < needed[k]:
			return 'IMPOSSIBLE'
	
	'''
	branching2
	'''
	for i, c in enumerate(chest):
		allKeys = holdingKeys[:]
		(number, openType, inside) = c
		for ii, cc in enumerate(chest):
			if i == ii:
				continue
			(nn, oo, inin) = cc
			allKeys.extend(inin)
		if openType not in allKeys:
			return 'IMPOSSIBLE'

	for i, c in enumerate(chest):
		(number, openType, inside) = c
		if openType in holdingKeys:
			newHoldingKeys = holdingKeys[:]
			newHoldingKeys.remove(openType)
			newHoldingKeys.extend(inside)
			result = openRecursively(chest[:i] + chest[i + 1:], newHoldingKeys)
			if result != 'IMPOSSIBLE':
				return [number] + result 

	return 'IMPOSSIBLE'

def openWay(chest, holdingKeys):
	result = openRecursively(chest, holdingKeys)
	if result != 'IMPOSSIBLE':
		for i, v in enumerate(result):
			result[i] = str(v)
		result = ' '.join(result)
	return result

T = int(raw_input())
for t in range(T):
	line = raw_input()
	K, N = line.split(' ')
	K = int(K)
	N = int(N)
	line = raw_input()
	holdingKeys = line.split(' ')
	chest = []
	for n in range(N):
		line = raw_input()
		item = line.split(' ')
		chest.append((n + 1, item[0], item[2:]))
	#print chest, holdingKeys
	print 'Case #' + str(t + 1) + ':', openWay(chest, holdingKeys)
