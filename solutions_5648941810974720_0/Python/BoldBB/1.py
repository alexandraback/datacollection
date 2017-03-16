with open("input1.txt", "r") as f:
	linenr = 0
	toInt = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
	known = {"W": "TWO", "G": "EIGHT", "X": "SIX", "Z": "ZERO", "U": "FOUR"}
	known2 = {"O": "ONE", "H": "THREE", "F": "FIVE", "S": "SEVEN"}
	known3 = {"N": "NINE"}
	for l in f.read().split("\n")[1:]:
		ori = l
		l = "".join(list(l))
		found = list()
		changed = True
		while changed:
			changed = False
			for i, c in enumerate(l):
				if c in known.keys():
					blown = list(l)
					for letter in known[c]:
						blown[blown.index(letter)] = False
					l = "".join(c for c in blown if c)
					found.append(known[c])
					changed = True
					break
		changed = True
		while changed:
			changed = False
			for i, c in enumerate(l):
				if c in known2.keys():
					blown = list(l)
					for letter in known2[c]:
						blown[blown.index(letter)] = False
					l = "".join(c for c in blown if c)
					found.append(known2[c])
					changed = True
					break
		changed = True

		while changed:
			changed = False
			for i, c in enumerate(l):
				if c in known3.keys():
					blown = list(l)

					for letter in known3[c]:
						blown[blown.index(letter)] = False

					l = "".join(c for c in blown if c)
					found.append(known3[c])
					changed = True
					break
		number = "".join(sorted(str(toInt.index(f)) for f in found))
		if len(found) > 0:
			linenr += 1
			print "Case #{}: {}".format(str(linenr), number)


"ONE"
"THREE"
"FIVE"
"SEVEN"
"NINE"