def solve(i):
	if not i:
		return 'INSOMNIA'
	x = i;
	s = set()
	while True:
		for d in str(x):
			s.add(int(d))
		if len(s) == 10:
			return x
		x += i;


f = open('input.txt' , 'r')
case = 0
for line in f:
	if case:
		print 'Case', '#' + str(case) + ':', solve(int(line))
	case += 1
f.close()

