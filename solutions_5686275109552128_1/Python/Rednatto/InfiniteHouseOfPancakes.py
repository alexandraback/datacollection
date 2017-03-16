import sys

def buildStacks( platesize, currstacks ):

	if platesize > len(currstacks):
		currstacks = currstacks + [0]*(platesize-len(currstacks))
	for i in range(0,platesize):
		currstacks[i] += 1

	return currstacks


def CalcXEat( xeats, currstacks ):

	specials = 0
	level = xeats
	height = len(currstacks)

	while level < height:
		specials += currstacks[level]
		level += xeats

	return xeats + specials

def CalCakes( currstacks ):
	
	height = len(currstacks)
	best = height
	numeats = 1
	Xval = best

	while numeats < best:
		
		Xval = CalcXEat( numeats, currstacks )
		# print best, Xval, numeats
		if Xval < best:
			best = Xval
		numeats += 1

	return best

if __name__ == '__main__':
	
	f = open(sys.argv[1])

	t = int(f.readline())

	for i in range(t):

		currstacks = []

		D = int(f.readline())
		Ps = f.readline().split(" ")

		for j in range(D):
			Pj = int(Ps[j])
			currstacks = buildStacks( Pj, currstacks )

		print( "Case #%d: %d" % ( (i+1), CalCakes(currstacks) ) )

