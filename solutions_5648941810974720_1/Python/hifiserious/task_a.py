t = int(raw_input())  
for i in xrange(1, t + 1):
	s = raw_input()
  	ls = list(s)

	zeroCount = ls.count('Z');
	for x in xrange(0, zeroCount):
	  	ls.remove('Z')
	  	ls.remove('E')
	  	ls.remove('R')
	  	ls.remove('O')


	twoCount = ls.count('W');
	for x in xrange(0, twoCount):
		ls.remove('T')
	  	ls.remove('W')
	  	ls.remove('O')

	sixCount = ls.count('X');
	for x in xrange(0, sixCount):
		ls.remove('S')
	  	ls.remove('I')
	  	ls.remove('X')

	eightCount = ls.count('G');
	for x in xrange(0, eightCount):
		ls.remove('E')
	  	ls.remove('I')
	  	ls.remove('G')
	  	ls.remove('H')
	  	ls.remove('T')

	threeCount = ls.count('H');
	for x in xrange(0, threeCount):
		ls.remove('T')
	  	ls.remove('H')
	  	ls.remove('R')
	  	ls.remove('E')
	  	ls.remove('E')

	fourCount = ls.count('R');
	for x in xrange(0, fourCount):
		ls.remove('F')
	  	ls.remove('O')
	  	ls.remove('U')
	  	ls.remove('R')

	fiveCount = ls.count('F');
	for x in xrange(0, fiveCount):
		ls.remove('F')
	  	ls.remove('I')
	  	ls.remove('V')
	  	ls.remove('E')

	sevenCount = ls.count('V');
	for x in xrange(0, sevenCount):
		ls.remove('S')
	  	ls.remove('E')
	  	ls.remove('V')
	  	ls.remove('E')
	  	ls.remove('N')

	nineCount = ls.count('I');
	for x in xrange(0, nineCount):
		ls.remove('N')
	  	ls.remove('I')
	  	ls.remove('N')
	  	ls.remove('E')

	oneCount = ls.count('N')

	result = '0' * zeroCount + '1' * oneCount + '2' * twoCount + '3' * threeCount + '4' * fourCount + '5' * fiveCount + '6' * sixCount + '7' * sevenCount + '8' * eightCount + '9' * nineCount

  	print "Case #{}: {}".format(i, result)