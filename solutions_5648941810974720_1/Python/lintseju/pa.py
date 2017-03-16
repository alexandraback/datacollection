from sys import argv, stdout

f = open(argv[1])
line = f.readline()
t = int(line)
c = 1
while t > 0:
	line = f.readline()
	ans = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	table = {}
	for char in line:
		table[char] = table.get(char, 0) + 1
	x = table.get('Z', 0)
	if x > 0:
		table['Z'] -= x
		table['E'] -= x
		table['R'] -= x
		table['O'] -= x
		ans[0] += x
	x = table.get('X', 0)
	if x > 0:
		table['S'] -= x
		table['I'] -= x
		table['X'] -= x
		ans[6] += x
	x = table.get('G', 0)
	if x > 0:
		table['E'] -= x
		table['I'] -= x
		table['G'] -= x
		table['H'] -= x
		table['T'] -= x
		ans[8] += x
	x = table.get('W', 0)
	if x > 0:
		table['T'] -= x
		table['W'] -= x
		table['O'] -= x
		ans[2] += x
	x = table.get('U', 0)
	if x > 0:
		table['F'] -= x
		table['O'] -= x
		table['U'] -= x
		table['R'] -= x
		ans[4] += x
	x = table.get('S', 0)
	if x > 0:
		table['S'] -= x
		table['E'] -= x
		table['V'] -= x
		table['E'] -= x
		table['N'] -= x
		ans[7] += x
	x = table.get('V', 0)
	if x > 0:
		table['F'] -= x
		table['I'] -= x
		table['V'] -= x
		table['E'] -= x
		ans[5] += x
	x = table.get('O', 0)
	if x > 0:
		table['O'] -= x
		table['N'] -= x
		table['E'] -= x
		ans[1] += x
	x = table.get('N', 0) / 2
	if x > 0:
		table['N'] -= x
		table['I'] -= x
		table['N'] -= x
		table['E'] -= x
		ans[9] += x
	x = table.get('T', 0)
	if x > 0:
		ans[3] += x
	stdout.write('Case #%d: ' % c)
	for i in xrange(len(ans)):
		for j in xrange(ans[i]):
			stdout.write(str(i))
	print
	t -= 1
	c += 1
