import math

def paintUsed(r, n):
	return (2*r+1+2*(r+2*n)+1)*(n+1)/2

def getRings(r, t):
	trial = math.ceil( (math.sqrt(4*r**2 - 4*r + 8*t +1) - 2*r - 3) / 4 +1)

	curr = trial

	while True:
		currUsed = paintUsed(r, curr)
		if currUsed > t:
			break
		curr += 1

	while True:
		prevUsed = paintUsed(r, curr-1)
		if prevUsed <= t:
			break
		curr -= 1
	return curr


if __name__ == '__main__':
	fIn = open('A-small-attempt0.in')
	fOut = open('output.txt', 'w')
	numOfTests = int(fIn.readline())

	results = []
	for t in range(numOfTests):
		r, paint = [int(x) for x in fIn.readline().split()]
		rings = getRings(r, paint)

		fOut.write("Case #%d: %d \n" % (t+1, rings))

