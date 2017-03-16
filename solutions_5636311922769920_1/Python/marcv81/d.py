import time

class Artwork:
	"""Interesting artworks with only 1 gold tile"""

	def __init__(self, block_length, gold_index, complexity):
		self._block_length = block_length
		self._gold_index = gold_index
		self._complexity = complexity
		self._power = [block_length**n for n in xrange(complexity)]

	def length(self):
		return len(self._block_length)**self._complexity

	def has_gold(self, index):
		for n in xrange(complexity):
			temp_index = (index / self._power[n]) % self._block_length
			if temp_index == self._gold_index:
				return True
		return False

def count_gold(artworks, index):
	count = 0
	for artwork in artworks:
		if artwork.has_gold(index):
			count += 1
	return count

def find_min_gold(artworks, min_gold, limit):

	cycles = 0

	best_count = -1
	best_index = -1

	for index in xrange(limit):
		count = count_gold(artworks, index)
		if count >= min_gold:
			return index
		if count > best_count:
			best_count = count
			best_index = index

		# Gives up after 25000 cycles and
		# goes with whatever max we have.
		# Does suck.
		cycles += 1
		if cycles > 10000:
			return best_index

	return None

# Only keep the artworks which don't have gold at index
def filter_artworks(artworks, index):
	filtered_artworks = []
	for artwork in artworks:
		if not artwork.has_gold(index):
			filtered_artworks.append(artwork)
	return filtered_artworks

def find_index_sequence(block_length, complexity, max_tries):

	artworks = []
	for n in xrange(block_length):
		artworks.append(Artwork(block_length, n, complexity))

	tries = 0
	indices = []
	while len(artworks) > 0 and tries < max_tries:

		(min_gold, remainder) = divmod(len(artworks), max_tries - tries)
		if remainder > 0: min_gold += 1

		# Peformance: on the first try check only the first half
		limit = block_length**complexity
		if tries == 0:
			(limit, remainder) = divmod(limit, 2)
			if remainder > 0: limit += 1

		index = find_min_gold(artworks, min_gold, limit)
		if index is None:
			return None

		indices.append(index + 1)
		artworks = filter_artworks(artworks, index)
		tries += 1

	if len(artworks) > 0:
		return None
	else:
		return indices

with open('D-large.in', 'r') as f:
	test_cases = int(f.readline())
	for test_case in xrange(1, test_cases + 1):

		line = f.readline()
		(block_length, complexity, max_tries) = (int(i) for i in line.split())

		indices = find_index_sequence(block_length, complexity, max_tries)
		if indices is None:
			print 'Case #' + str(test_case) + ': IMPOSSIBLE'
		else:
			print 'Case #' + str(test_case) + ': ' + ' '.join(str(i) for i in indices)
