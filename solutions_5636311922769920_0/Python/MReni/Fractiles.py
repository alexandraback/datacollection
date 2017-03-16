import math

max_number = 0
K = 3 # K is original length
C = 2 # C is complexity
S = 3 # S is minimum required

def is_solvable(K, C, S):
	return S >= math.ceil(K*1.0/C)
	# if C < K and S < K:
	# 	return False 
	# return True

def get_tile_in_range(tile, K):
	return max(0, min(tile, K))

def get_tile_number(required_tiles, K, C):
	if C == 1:
		return required_tiles[0]
	max_position = K ** C
	base_tile = get_tile_in_range(required_tiles[-1], K)
	expected_position = base_tile % K if base_tile % K != 0 else K
	for i in range(1, C):
		tile_number = get_tile_in_range(required_tiles[i-1], K)
		expected_position += pow(K, (C-i)) * (tile_number - 1)
	# print "max_position: {} and expected_position: {}".format(str(max_position), str(expected_position))
	return min(max_position, expected_position)

def get_tiles(K, C, S):
	global max_number
	tiles = set()
	for i in range(1, K+1, C):
		# print i
		required_tiles = range(i, i+C)
		# print required_tiles
		tile_number = get_tile_number(required_tiles, K, C)
		# print tile_number
		if tile_number > max_number:
			max_number = tile_number
			# print "MAX: @@@@@@@@@@@@@@ {}".format(str(tile_number))
		tiles.add(str(tile_number))
	return tiles

def map_tiles(K, C):
	base_tiles = [str(i) for i in range(1, K+1)]
	tiles = base_tiles
	for i in range(1, C):
		new_tiles = []
		for tile in tiles:
			for base_tile in base_tiles:
				new_tiles.append(base_tile + tile)
		tiles = new_tiles
	count = 1
	for tile in tiles:
		print "Count {} : {}".format(str(count), tile)
		count = count + 1

count = 1
with open('dataD2', 'rb') as data:
	for line in data:
		K, C, S = [int(x) for x in line.replace('\n', '').split(' ')]
		# print "K: {}, C: {}".format(str(K), str(C), str(S))
		# if count == 57:
		# 	map_tiles(K, C)
		if not is_solvable(K, C, S):
			print "Case #" + str(count) + ": IMPOSSIBLE"
		else:
			tiles = get_tiles(K, C, S)
			tiles = list(tiles)
			tiles.sort()
			# print "K: {}, C: {}, S:{}, final: {}".format(str(K), str(C), str(S), str(len(tiles)))
			# print "Rule Followed? {}".format(str(len(tiles) <= S))
			print "Case #" + str(count) + ": " + ' '.join(tiles) 
			# print "Case #" + str(count) + ": " + ' '.join(get_tiles(K, C, S)) 
		count = count + 1