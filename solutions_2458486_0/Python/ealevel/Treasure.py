import sys
from collections import Counter
sys.setrecursionlimit(10001)

class Chest:
	def __init__(self, keytype, keys):
		self.keytype = keytype
		self.keys = Counter(keys)

def open(mask, keychain):
	if mask == done:
		return True
	if mask in failed:
		return False
	for i in xrange(n):
		if mask & (1 << i) == 0 and keychain[chests[i].keytype] > 0: # Closed chest
			keychain[chests[i].keytype] -= 1
			path.append(i + 1)
			if open(mask | (1 << i), keychain + chests[i].keys):
				return True
			path.pop()
			keychain[chests[i].keytype] += 1
	failed.add(mask)
	return False

T = int(sys.stdin.readline().strip())
for t in xrange(1, T+1):
	k, n = map(int, sys.stdin.readline().strip().split())
	keys = map(int, sys.stdin.readline().strip().split())
	chests = []
	for _ in xrange(n):
		line = map(int, sys.stdin.readline().strip().split())
		chests.append(Chest(line[0], line[2:]))
	done = (1 << n) - 1
	path = []
	failed = set()
	keychain = Counter(keys)
	print "Case #{}: {}".format(t, " ".join(str(x) for x in path) if open(0, keychain) else "IMPOSSIBLE")
