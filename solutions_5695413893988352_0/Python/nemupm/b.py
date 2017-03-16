num_test_cases = input()
for nc in xrange(1, num_test_cases+1):
	C, J = raw_input().split()
	length = len(C)
	candidates = []
	for position in xrange(length):
		for C_is_bigger_than_J in [True, False]:
			c = ""
			j = ""
			if C_is_bigger_than_J:
				for i in xrange(length):
					if i == position:
						if C[i] == "?" and J[i] != "?":
							if J[i] == "9":
								break
							c += str(int(J[i]) + 1)
							j += J[i]
						elif C[i] != "?" and J[i] == "?":
							if C[i] == "0":
								break
							c += C[i]
							j += str(int(C[i]) - 1)
						elif C[i] == "?" and J[i] == "?":
							c += "1"
							j += "0"
						else:
							if int(C[i]) <= int(J[i]):
								break
							c += C[i]
							j += J[i]
					elif i < position:
						if C[i] == "?" and J[i] != "?":
							c += J[i]
							j += J[i]
						elif C[i] != "?" and J[i] == "?":
							c += C[i]
							j += C[i]
						elif C[i] == "?" and J[i] == "?":
							c += "0"
							j += "0"
						else:
							if C[i] != J[i]:
								break
							c += J[i]
							j += J[i]
					else:
						if C[i] == "?" and J[i] != "?":
							c += "0"
							j += J[i]
						elif C[i] != "?" and J[i] == "?":
							c += C[i]
							j += "9"
						elif C[i] == "?" and J[i] == "?":
							c += "0"
							j += "9"
						else:
							c += C[i]
							j += J[i]
				if len(c) == length:
					candidates.append((max(int(c)-int(j),int(j)-int(c)), int(c)+int(j), c, j))
			else:
				for i in xrange(length):
					if i == position:
						if C[i] == "?" and J[i] != "?":
							if J[i] == "0":
								break
							c += str(int(J[i]) - 1)
							j += J[i]
						elif C[i] != "?" and J[i] == "?":
							if C[i] == "9":
								break
							c += C[i]
							j += str(int(C[i]) + 1)
						elif C[i] == "?" and J[i] == "?":
							c += "0"
							j += "1"
						else:
							if int(C[i]) >= int(J[i]):
								break
							c += C[i]
							j += J[i]
					elif i < position:
						if C[i] == "?" and J[i] != "?":
							c += J[i]
							j += J[i]
						elif C[i] != "?" and J[i] == "?":
							c += C[i]
							j += C[i]
						elif C[i] == "?" and J[i] == "?":
							c += "0"
							j += "0"
						else:
							if C[i] != J[i]:
								break
							c += J[i]
							j += J[i]
					else:
						if C[i] == "?" and J[i] != "?":
							c += "9"
							j += J[i]
						elif C[i] != "?" and J[i] == "?":
							c += C[i]
							j += "0"
						elif C[i] == "?" and J[i] == "?":
							c += "9"
							j += "0"
						else:
							c += C[i]
							j += J[i]
				if len(c) == length:
					candidates.append((max(int(c)-int(j),int(j)-int(c)), int(c)+int(j), c, j))
	# check whether c can be the same as j
	c = ""
	j = ""
	for i in xrange(length):
		if C[i] == "?" and J[i] != "?":
			c += J[i]
			j += J[i]
		elif C[i] != "?" and J[i] == "?":
			c += C[i]
			j += C[i]
		elif C[i] == "?" and J[i] == "?":
			c += "0"
			j += "0"
		else:
			if C[i] != J[i]:
				break
			c += J[i]
			j += J[i]
	if len(c) == length:
		candidates.append((max(int(c)-int(j),int(j)-int(c)), int(c)+int(j), c, j))
	candidates.sort()

	print "Case #%d: %s" % (nc, candidates[0][2] + " " + candidates[0][3])