import sys


cache = {}

def solve(ownmote, motes):
	motes.sort()
	# print(motes)
	changes = 0
	while len(motes) > 0:
		if motes[0] < ownmote:
			ownmote += motes[0]
			motes = motes[1:]
		else:
			if ownmote > 1:
				moteadd = [ownmote-1] + motes
				kadd = str(ownmote) + ',' + ','.join(str(x) for x in moteadd)
				if kadd in cache:
					changesadd = cache[kadd]
				else:
					changesadd = solve(ownmote, moteadd)
			else:
				changesadd = 1000000000000000
			motedel = motes[1:]
			kdel = str(ownmote) + ',' + ','.join(str(x) for x in motedel)
			if kdel in cache:
				changesdel = cache[kdel]
			else:
				changesdel = solve(ownmote, motedel)
			if changesdel < changesadd:
				cache[kdel] = changesdel
				return 1 + changesdel
			else:
				cache[kadd] = changesadd
				return 1 + changesadd

	return changes

n = int(sys.stdin.readline())
for c in range(n):
	cache = {}
	[ownmote, nummotes] = [int(x) for x in sys.stdin.readline().split()]
	motes = [int(x) for x in sys.stdin.readline().split()]
	assert(nummotes == len(motes))
	motes.sort()
	print("Case #%d: %d" % (c+1, solve(ownmote, motes)))
