import itertools

def getValue(tupnum):
	total = 0
	m = 1
	for n in reversed(tupnum):
		total += n * m
		m *= 10
	return total

def getCombos(numberstring, postfix):
	numlist = [int(c) if c != "?" else c for c in numberstring]
	indexlist = [i for i, c in enumerate(numlist) if c == "?"]
	combos = list()
	for n in itertools.product((0,1,2,3,4,5,6,7,8,9), repeat = numberstring.count("?")):
		for i, num in zip(indexlist, n):
			numlist[i] = num
		combos.append((tuple(numlist), postfix))
	return combos

with open("input2.txt", "r") as f:
	linenr = 0

	for l in f.read().split("\n")[1:]:
		ori = l
		num1, num2 = l.split(" ")
		onlyquest = True
		for i, c in enumerate(num1):
			if c != "?" and num2[i] != "?":
				onlyquest = False
		if onlyquest:
			for i, c in enumerate(num2):
				if c != "?":
					num1 = num1[:i] + c + num1[i+1:]
			for i, c in enumerate(num1):
				if c == "?":
					num1 = num1[:i] + "0" + num1[i+1:]
			num2 = num1
		else:
			mindist = 9999999
			best = None
			combos = sorted(getCombos(num1, 0) + getCombos(num2, 1))

			for i, c in enumerate(combos):
				if c[1] == 0:
					for j in range(i, max(i - mindist - 1, -1), -1):
						if combos[j][1] == 1:
							v1, v2 = getValue(combos[i][0]), getValue(combos[j][0])
							if abs(v2 - v1) < mindist:
								mindist = abs(v2 - v1)
								best = (combos[i], combos[j])
							break
					for j in range(i, min(i + mindist + 1, len(combos))):
						if combos[j][1] == 1:
							v1, v2 = getValue(combos[i][0]), getValue(combos[j][0])
							if abs(v2 - v1) < mindist:
								mindist = abs(v2 - v1)
								best = (combos[i], combos[j])
							break
			num1 = "".join(str(s) for s in best[0][0])
			num2 = "".join(str(s) for s in best[1][0])
		if len(l) > 0:
			linenr += 1
			print "Case #{}: {} {}".format(str(linenr), num1, num2)