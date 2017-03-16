import sys

file = sys.argv[1]

lines = open(file).readlines()
N = int(lines[0])

currentLine = 1

for case in range(N):
	P,Q = map(int,lines[currentLine].split('/'))
	currentLine = currentLine + 1

	lowestGen = 0
	for i in range(1,41):
		#print "Gen {} {} {}".format(i, P , Q)
		P = P * 2
		if P >= Q:
			if lowestGen == 0:
				lowestGen = i
			P = P - Q
		if P == 0:
			break
	if P == 0:
		print "Case #{}: {}".format(case + 1 ,lowestGen )
	else:
		print "Case #{}: impossible".format(case + 1 )