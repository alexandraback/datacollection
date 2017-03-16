import fileinput
stdin = fileinput.input()

def solveCase():
	n,s = stdin.next().split()
	n = int(n)
	s = [int(c) for c in s]

	needed = n
	standing = 0
	friends = 0
	for shyness,k in enumerate(s):
		if needed<=0:
			break
		if standing<shyness:
			if needed<shyness-standing:
				friends += needed
				return friends
			else:
				addedFriends = shyness-standing
				friends += addedFriends
				standing += addedFriends
		standing += k
	return friends

for case in xrange(int(stdin.next())):
	print "Case #{0}: {1}".format(case+1,solveCase())
