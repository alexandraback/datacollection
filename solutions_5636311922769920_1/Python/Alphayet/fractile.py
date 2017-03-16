import sys
import math

def find_pos(K, C, S):
	minS = int(math.ceil(K * 1.0 / C))
	if minS > S:
		return False
	blocks = [1]
	if minS > 1:
		reminder = minS * C - K
		blocks.append(blocks[0] + C - reminder)
		for i in range(minS-2):
			blocks.append(blocks[1 + i] + C)

	c = C
	ext_blocks = blocks[:]

	for i in range(len(blocks)):
		ext_blocks[i] =  1 + K ** (c-1) * (blocks[i]-1)
	while c > 1:
		col_per_b = K ** (c-2)
		for i in range(len(ext_blocks)):
			ext_blocks[i] += (blocks[i] + C-c) * col_per_b
		c -= 1
	return ext_blocks

filename = sys.argv[1]

with open(filename, 'r') as fh:
	T = int(fh.readline().strip())
	for t in range(T):
		K, C, S = map(int, fh.readline().strip().split(' '))
		pos = find_pos(K, C, S)
		if pos:
			print "Case #%d: %s" % (t+1, ' '.join(
				map(lambda x: str(x), pos)))
		else:
			print "Case #%d: IMPOSSIBLE" % (t+1)
