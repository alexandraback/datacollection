f = open('A-small-attempt0.in', 'r')
w = open('A-small-attempt0.out', 'w')
test = int(f.readline())
for case in range(test):
	w.write('Case #%i: ' %(case + 1))
	n = int(f.readline())
	if n == 0:
		w.write('INSOMNIA')
	else:
		s = set()
		for i in range(10):
			s.add(str(i))
		m = 0
		while len(s) > 0:
			m += n
			temp = str(m)
			for i in range(len(temp)):
				s.discard(temp[i])
		w.write(str(m))
	w.write('\n')