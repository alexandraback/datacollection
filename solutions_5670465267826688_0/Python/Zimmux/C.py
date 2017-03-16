import fileinput
stdin = fileinput.input()

rules = {
	"11":"1", "1i":"i", "1j":"j", "1k":"k",
	"i1":"i", "ii":"-", "ij":"k", "ik":"J",
	"j1":"j", "ji":"K", "jj":"-", "jk":"i",
	"k1":"k", "ki":"j", "kj":"I", "kk":"-",
	
	"1-":"-", "1I":"I", "1J":"J", "1K":"K",
	"i-":"I", "iI":"1", "iJ":"K", "iK":"j",
	"j-":"J", "jI":"k", "jJ":"1", "jK":"I",
	"k-":"K", "kI":"J", "kJ":"i", "kK":"1",
	
	"-1":"-", "-i":"I", "-j":"J", "-k":"K",
	"I1":"I", "Ii":"1", "Ij":"K", "Ik":"j",
	"J1":"J", "Ji":"k", "Jj":"1", "Jk":"I",
	"K1":"K", "Ki":"J", "Kj":"i", "Kk":"1",

	"--":"1", "-I":"i", "-J":"j", "-K":"k",
	"I-":"i", "II":"-", "IJ":"k", "IK":"J",
	"J-":"j", "JI":"K", "JJ":"-", "JK":"i",
	"K-":"k", "KI":"j", "KJ":"I", "KK":"-",
}

def scanL(s):
	r = "1"
	res = []
	for c in s:
		r = rules[r+c]
		res.append(r)
	return res

def solveCase():
	L,X = map(int,stdin.next().split())
	s = stdin.next().split()[0]
	# each of the letters i, j and k needs at most 4 entire blocks (bbbb=b) => 3*4
	# the splits between i,j and j,k may occur in at most 2 other blocks    => 1*4
	# so take X = 4*4 + X mod 4*4
	if X>4*4:
		X = 4*4+(X%(4*4))
	s = s*X
	hd = scanL(s)
	for i,evI in enumerate(hd):
		if evI=='i':
			for j,evIJ in enumerate(hd[i+1:-1]):
				if evIJ=='k':
					if hd[-1]=='-':
						return "YES"
					break
			break
	return "NO"

for case in xrange(int(stdin.next())):
	print "Case #{0}: {1}".format(case+1,solveCase())