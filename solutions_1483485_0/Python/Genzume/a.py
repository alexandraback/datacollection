from collections import defaultdict

g2e = defaultdict(str)
g2e['a'] = 'y'
g2e['b'] = 'h'
g2e['c'] = 'e'
g2e['d'] = 's'
g2e['e'] = 'o'
g2e['f'] = 'c'
g2e['g'] = 'v'
g2e['h'] = 'x'
g2e['i'] = 'd'
g2e['j'] = 'u'
g2e['k'] = 'i'
g2e['l'] = 'g'
g2e['m'] = 'l'
g2e['n'] = 'b'
g2e['o'] = 'k'
g2e['p'] = 'r'
g2e['q'] = 'z'
g2e['r'] = 't'
g2e['s'] = 'n'
g2e['t'] = 'w'
g2e['u'] = 'j'
g2e['v'] = 'p'
g2e['w'] = 'f'
g2e['x'] = 'm'
g2e['y'] = 'a'
g2e['z'] = 'q'

file = open('a.in', 'r')
out = open('a.out', 'w')
lines = int(file.readline().rstrip())

for i in range(1, lines + 1):
	line = file.readline().rstrip()
	output = []
	for ch in line:
		if ch == ' ':
			output.append(ch)
		else:
			output.append(g2e[ch])
			
	result = "Case #%d: %s" % (i, ''.join(output))
	out.write(result + '\n')
	print result
	
file.close()