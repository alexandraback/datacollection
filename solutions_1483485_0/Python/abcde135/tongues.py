
def write_case(n, s, f):
    f.write("Case #%i: %s\n" % (n, s))

def create_mapping():
	s = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv"
	t = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up"

	mapping = {}

	for (c,d) in zip(s,t):
		if c in mapping and d != mapping[c]:
			print "Error: %s %s" % (c, d)
		mapping[c] = d

	mapping['q'] = 'z'
	mapping['z'] = 'q'

	#for c in sorted(mapping):
	#	print c, mapping[c]

	#print set([chr(x) for x in range(ord('a'), ord('z')+1)]).difference(mapping.keys())
	#print set([chr(x) for x in range(ord('a'), ord('z')+1)]).difference(mapping.values())

	return mapping

def solve(infilename, outfilename):
	f = open(infilename)
	g = open(outfilename, 'w')

	T = int(f.readline())

	mapping = create_mapping()

	for n in range(T):
		line = f.readline().strip()
		english = "".join([mapping[c] for c in line])
		write_case(n+1, english, g)

	f.close()
	g.close()

if __name__ == '__main__':
#	solve('tongues-sample.in', 'tongues-sample.out')
	solve('A-small-attempt0.in', 'A-small-attempt0.out')
