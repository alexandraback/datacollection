def analyse(b, m):

	maxWays = genMaxWays(b-2)
	

	i = 0
	while i < len(maxWays) and maxWays[i] < m:
		i += 1

	if i >= len(maxWays):
		print(b,m)
		return "IMPOSSIBLE"
	else:
		slides = [[0]*i for _ in range(i)]
		for k in range(i):
			for j in range(i):
				if k < j:
					slides[k][j] = 1

		#print(i, maxWays)
		#printS(slides)
		for l in range(len(slides)):
			slides[l] = padWithZeroes(slides[l],b)
		
		

		#printS(slides)
		while len(slides) < b-1:
			slides.insert(0, [0]*b)

		#printS(slides)
		if maxWays[i] == m:
			slides.insert(0, padWithZeroes([1]*i,b))
		else:
			binaryRep = [int(c) for c in bin(m)[2:]]
			slides.insert(0, padWithZeroes(binaryRep + [0],b))

		

		answer = "POSSIBLE \n" + "\n".join([" ".join([str(v) for v in l]) for l in slides])
		#printS(slides)

		w = count(slides)
		if m != w:
			print("ERROR!", m, w)

		return answer




def genMaxWays(n):
	ways = [0,1]

	for i in range(n):
		ways.append(1+sum(ways))
	return ways

def padWithZeroes(l, n):
	return [0]*(n-len(l)) + l

def printS(slides):
	print("")
	for s in slides:
		print(s)

def count(slides):
	slides = slides[::]
	slides[-1][-1] = 1
	for i in reversed(range(len(slides))):
		for j in reversed(range(len(slides))):
			if slides[i][j] == 1:
				slides[i][j] = sum(slides[j])
	return sum(slides[0])

def run(name):
	lines = [l.rstrip() for l in open(name + ".in", mode='r')]
	n = int(lines[0])
	
	out = open(name + ".out",mode='w')
	for i in range(n):
		b, m = [int(v) for v in lines[i+1].split(" ")]
		answer = analyse(b,m)
		out.write("Case #" + str(i+1) + ": " + answer + "\n")
	out.close()

#analyse(5, 2)
run("B-small-attempt2")