import sys

input = open(sys.argv[1], 'r')
t = int(input.readline()[:-1])
for x in range(1, t+1):
	N = int(input.readline()[:-1])
	naomi = input.readline()[:-1].split()
	ken = input.readline()[:-1].split()
	def f(x):
		return float(x)
	naomi = map(f, naomi)
	ken = map(f, ken)
	naomi.sort()
	ken.sort()
	optimal = 0
	deceit = 0
	indexNaomi = 0
	indexKen = 0
	for y in range(0, N):
		if indexNaomi < N:
			kenBrick = ken[y]
			if kenBrick < naomi[indexNaomi]:
				indexNaomi+=1
				deceit += 1
			else:
				indexNaomi+=1
				while (indexNaomi < N) and (kenBrick >= naomi[indexNaomi]):
					indexNaomi+=1
				if (indexNaomi < N):
					deceit += 1
					indexNaomi += 1
	for y in range(0, N):
		if indexKen < N:
			naomiBrick = naomi[y]
			if ken[indexKen] > naomiBrick:
				indexKen+=1
			else:
				indexKen += 1
				while (indexKen < N) and (ken[indexKen] <= naomiBrick):
					indexKen+=1
				if (indexKen < N):
					indexKen += 1
				else:
					optimal += 1
		else:
			optimal += 1
	print "Case #" + str(x) + ": " + str(deceit) + " " + str(optimal)



