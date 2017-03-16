import sys

a = []
b = []
def recurse(sum1, set1, sum2, set2, i, bb):
	if sum1 != 0 and sum1 == sum2:
		global a
		a = set1
		global b
		b = set2
		return True
	if i >= len(bb):
		return False
	# dont add
	if recurse(sum1, list(set1), sum2, list(set2), i+1, bb):
		return True
	# add to set 1
	sum1 += bb[i]
	set1.append(bb[i])
	if recurse(sum1, list(set1), sum2, list(set2), i+1, bb):
		return True
	# add to set 2
	sum1 -= bb[i]
	set1 = set1[:-1]
	if i == 0: print set1, set2
	sum2 += bb[i]
	set2.append(bb[i])
	if recurse(sum1, list(set1), sum2, list(set2), i+1, bb):
		return True
	return False

def solve(n, s):
	s = sorted(s)
	if not recurse(0, [], 0, [], 0, s):
		return ['Impossible']
	s1 = ''
	for i in xrange(len(a)):
		if i > 0:
			s1 += ' '
		s1 += str(a[i])
	s2 = ''
	for i in xrange(len(b)):
		if i > 0:
			s2 += ' '
		s2 += str(b[i])
	return [s1, s2]
		
if __name__ == '__main__':
	fin = sys.stdin
	if len(sys.argv) > 1:
		fn = sys.argv[1]
		if fn != '-':
			fin = open(fn)
	fout = open('c.out', 'w')
	t = int(fin.readline())
	for i in range(t):
		l = fin.readline().strip().split(' ')
		n = int(l[0])
		l = l[1:]
		s = [int(k) for k in l]
		ss = 'Case #%d:'%(i+1)
		fout.write(ss+'\n')
		print ss
		for l in solve(n, s):
			fout.write(l+'\n')
			print l
	fin.close()
	fout.close()

