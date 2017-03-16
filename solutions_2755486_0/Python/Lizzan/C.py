"""Code written using Python 2.7.2, http://www.python.org/"""

import string



def calc(case):
	print case

	attacks = {}
	for tribe in case:
		(d, n, w, e, s, delta_d, delta_p, delta_s) = tribe
		for i in range(0, n):

			day = d + (i * delta_d)
			east = e + (i * delta_p)
			west = w + (i * delta_p)
			strength = s + (i * delta_s)
			
			if day in attacks:
				attacks[day] += [{'W': west, 'E': east, 'S': strength}]
			else:
				attacks[day] = [{'W': west, 'E': east, 'S': strength}]


	print attacks

	wall = {}
	breaches = 0

	for day in sorted(attacks.keys()):
		print 'Day:', day, 'attacks:', len(attacks[day])
		build = []
		for attack in attacks[day]:
			for i in range(attack['W'], attack['E']):
				if not i in wall or wall[i] < attack['S']:
					breaches += 1
					build += [(e, attack['S']) for e in range(attack['W'], attack['E'])]
					break

		print 'Build', build
		for b in build:
			(i, h) = b
			if i in wall:
				wall[i] = max(h, wall[i])
			else:
				wall[i] = h

			

	return breaches	


f = open('C-small.in', 'r')
lines = [r.strip() for r in f.readlines()]
f.close()
c = int(lines[0].split()[0])
lines = lines[1:]
#print c

cases = []
while len(lines) > 0:
	rows = int(lines[0].split(' ')[0])
	#print rows
	introws = []
	for row in lines[1:rows+1]:
		introws += [[int(i) for i in row.split(' ')]]

	cases += [introws]
	lines = lines[rows+1:]

#print cases

of = open('output_c_small.txt', 'w')

for idx, case in enumerate(cases):
	of.write('Case #%(idx)i: %(i)s\n' % {'idx': idx + 1, 'i': calc(case)})

of.close()

