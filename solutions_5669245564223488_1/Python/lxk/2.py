def fact(n):
	f = 1
	for i in range(2, n + 1):
		f = mul(f, i)
	return f


def mul(a, b):
	return (a * b) % 1000000007


def has_common_char(s1, s2):
	return len(set(s1).intersection(s2)) > 0


def optimize_str(s):
	optimizedStr = ""

	prevCh = 0
	for ch in s:
		if ch == prevCh:
			continue
		optimizedStr += ch
		prevCh = ch

	return optimizedStr


def is_chain_valid(chain):
	chars = dict()
	for s in chain:
		s = optimize_str(s)
		sLen = len(s)

		if sLen <= 1:
			continue

		for i in range(0, sLen):
			ch = s[i]
			if not ch in chars:
				chars[ch] = [0, 0, 0]

			if i == 0:
				# begin
				chars[ch][0] += 1
			elif i == sLen - 1:
				# end
				chars[ch][2] += 1
			else:
				# middle
				chars[ch][1] += 1

	if len(chars) == 0:
		return True

	beginExist = False
	endExist = False

	for ch in chars.values():
		if ch == [1, 0, 0]:
			beginExist = True
		elif ch == [0, 0, 1]:
			endExist = True
		elif ch == [0, 1, 0]:
			# just in middle
			continue
		elif ch == [1, 0, 1]:
			# has start and end
			continue
		else:
			return False

	return beginExist and endExist


def is_single_char(s):
	return len(set(s)) == 1


def count_permutations(chain):
	if not is_chain_valid(chain):
		return 0

	singleCharStrings = dict()
	for s in chain:
		if is_single_char(s):
			ch = s[0]
			if not ch in singleCharStrings:
				singleCharStrings[ch] = 0
			singleCharStrings[ch] += 1

	res = 1
	for value in singleCharStrings.values():
		if value > 1:
			res = mul(res, fact(value))

	return res


def merge_chains(chain1, chain2):
	for s2 in chain2:
		for s1 in chain1:
			if has_common_char(s1, s2):
				return True

	return False


fin = open('input.txt')
lines = fin.read().split("\n")

testsCount = int(lines[0])
for testCase in range(1, testsCount + 1):
	strings = lines[(testCase - 1) * 2 + 2].split()

	stringChains = []

	# initial chains
	for s in strings:
		chainFound = False
		for chain in stringChains:
			for chainS in chain:
				if has_common_char(s, chainS):
					chain.append(s)
					chainFound = True
					break

			if chainFound:
				break

		if not chainFound:
			stringChains.append([s])

	# merged chains
	chainsMerged = True
	while chainsMerged:
		chainsMerged = False

		countChains = len(stringChains)
		for i in range(0, countChains - 1):
			for j in range(i + 1, countChains):
				if merge_chains(stringChains[i], stringChains[j]):
					stringChains[i] += stringChains[j]
					del stringChains[j]

					chainsMerged = True
					break

			if chainsMerged:
				break

	chainsCount = len(stringChains)
	res = fact(chainsCount)

	for chain in stringChains:
		res = mul(res, count_permutations(chain))
		if res == 0:
			break

	print "Case #" + str(testCase) + ":", res