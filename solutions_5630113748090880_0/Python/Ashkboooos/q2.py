from collections import Counter
file_n = 'B-small-attempt1.in'
content = open(file_n , 'r').read().splitlines()
T, output   = int(content[0]), ''
line_n = 0
for i in xrange(1, T + 1):
	line_n +=1 
	n =  map(int, content[line_n].split())[0]
	print n
	case = "Case #%d: " %i
	rows = []
	min_a, max_a = 2600, -1
	d = []
	for j in xrange((2 * n - 1)):
		line_n += 1
		print 'line', line_n
		r =  map(int, content[line_n].split())
		rows.append(r)
		if min(r) < min_a:
			min_a = min(r)
		d.extend(r)
	print d
	di = Counter(d)
	missing = []
	for key in di:
		if di[key] % 2==1:
			missing.append(key)
	s = sorted(missing)
	case += " ".join(map(str, s))
	print case
	output += case + '\n'
file_out = file_n.replace('.in','.out')
f = open(file_out, 'w')
f.write(output)
f.close()


