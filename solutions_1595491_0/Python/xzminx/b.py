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
	

def solve(n, s, p, scores):
	ctr = 0
	for score in scores:
		a = int(score / 3)
		togo = score - 3*a
		#print score
		if a >= p:
			ctr+=1
			#print '\tavg je veci'
		elif a+1 >= p and togo > 0:
			ctr+=1
			#print '\tza jedan ima'
		elif a+2 >= p and togo > 1 and s > 0:
			ctr+=1
			s-=1
			#print '\tcudan za 2'
		elif togo == 0 and a > 0 and a+1 >= p and s > 0:
			ctr+=1
			s-=1
			#print '\tpomak iza za 1 kod djeljivog s 3'
		
	return ctr
	

if __name__ == '__main__':
	fin = sys.stdin
	if len(sys.argv) > 1:
		fn = sys.argv[1]
		if fn != '-':
			fin = open(fn)
	fout = open('b.out', 'w')
	t = int(fin.readline())
	for i in range(t):
		g = fin.readline().strip().split(' ')
		n = int(g[0])
		s = int(g[1])
		p = int(g[2])
		scores = []
		for j in range(3, 3+n):
			scores.append(int(g[j]))
		ss = 'Case #%d:'%(i+1) + ' ' + str(solve(n, s, p, scores))
		print ss
		fout.write(ss+'\n')
	fin.close()
	fout.close()
