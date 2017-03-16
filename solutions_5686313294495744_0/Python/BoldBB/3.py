import itertools

def flatten(l):
	flattened = list()
	if isinstance(l, list) or isinstance(l, tuple):
		for node in l:
			flattened += flatten(node)
	else:
		return [l]
	return flattened

with open("input3.txt", "r") as f:
	linenr = 0
	lines = f.read().split("\n")[1:]
	casenr = 0

	while linenr < len(lines):
		cases = int(lines[linenr])
		linenr += 1
		allwords = list()
		firstwords = list()
		lastwords = list()
		for i in range(cases):
			words = tuple(lines[linenr].split(" "))
			allwords.append(words)
			firstwords.append(words[0])
			lastwords.append(words[1])
			linenr += 1
		originals = list()
		flatwords = flatten(allwords)
		for combo in allwords:
			if firstwords.count(combo[0]) == 1 or lastwords.count(combo[1]) == 1:
				originals.append(combo)
		casenr += 1
		print "Case #{}: {}".format(str(casenr), str(len(allwords) - len(originals)))