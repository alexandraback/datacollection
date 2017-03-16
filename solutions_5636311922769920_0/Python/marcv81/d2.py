def interesting_artworks(length, complexity):

	artworks = []

	# Trick: we do not generate all the possible artworks,
	# just the first few blocks of well-chosen ones to cover
	# the worst case scenario.

	for i in xrange(1, length):
		tiles = []
		for j in xrange(i): tiles.append('L')
		tiles.append('G')
		for j in xrange(length-i-1): tiles.append('L')
		artworks.append(str().join(tiles))

	if complexity == 1:
		tiles = ['G'] + ['L'] * (length-1)
		artworks.append(str().join(tiles))
	else:
		tiles = ['G'] * length
		artworks.append(str().join(tiles))

	return artworks

def find_gold_index(artworks):
	length = len(artworks[0])

	# Count chances of G per index
	count = [0] * length
	for artwork in artworks:
		for i in xrange(length):
			if artwork[i] == 'G':
				count[i] += 1

	# Return index with best chance of G
	best_index = 0
	best_value = count[0]
	for i in xrange(1, length):
		if count[i] > best_value:
			best_index = i
			best_value = count[i]
	return best_index

# Keep artworks with no G at index
def filter_artworks(artworks, index):
	filtered_artworks = []
	for artwork in artworks:
		if artwork[index] == 'L':
			filtered_artworks.append(artwork)
	return filtered_artworks

def find_index_sequence(length, complexity, max_tries):

	artworks = interesting_artworks(length, complexity)

	tries = 0
	indices = []
	while len(artworks) > 0 and tries < max_tries:

		# Pick the index with the best chance of G
		index = find_gold_index(artworks)
		indices.append(index + 1)

		# Only keep the artworks where we did not find G
		artworks = filter_artworks(artworks, index)

		tries += 1

	if len(artworks) > 0:
		return None
	else:
		return indices

with open('D-small-attempt1.in', 'r') as f:
	test_cases = int(f.readline())
	for test_case in xrange(1, test_cases + 1):

		line = f.readline()
		(seed_length, complexity, max_tries) = (int(i) for i in line.split())

		indices = find_index_sequence(seed_length, complexity, max_tries)
		if indices is None:
			print 'Case #' + str(test_case) + ': IMPOSSIBLE'
		else:
			print 'Case #' + str(test_case) + ': ' + ' '.join(str(i) for i in indices)
