import sys

def read_tests(fname):
	fin = open(fname, 'r')
	tests = []
	t = int(fin.readline())
	for i in range(t):
		test = []
		s = fin.readline().strip().split(' ')
		for j in range(int(s[0])):
			test.append([s[1+j*2], int(s[2+j*2])])
		tests.append(test)
	fin.close()
	return tests
	
	
def translate(g, mapping):
	s = ''
	for ch in g:
		s += mapping.get(ch,ch)
	return s
	
def fill_mapping(mapping):
	g = 'y n f i c w l b k u o m x s e v z p d r j g a t h a q'
	s = 'a b c d e f g h i j k l m n o p q r s t u v y w x y z'
	g = g.split(' ')
	s = s.split(' ')
	for i in range(len(g)):
		mapping[g[i]] = s[i]
	

if __name__ == '__main__':
	mapping = {}
	fill_mapping(mapping)
	
	fin = sys.stdin
	if len(sys.argv) > 1:
		fn = sys.argv[1]
		if fn != '-':
			fin = open(fn)
	fout = open('a.out', 'w')
	t = int(fin.readline())
	for i in range(t):
		g = fin.readline().strip()
		ss = 'Case #%d:'%(i+1) + ' ' + translate(g, mapping)
		print ss
		fout.write(ss+'\n')
	fout.close()
