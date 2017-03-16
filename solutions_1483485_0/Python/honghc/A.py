instring = 	'ynficwlbkuomxsevzpdrjgthaq *'
outstring = 'abcdefghijklmnopqrstuvwxyz *'

def get_output_l(l):
	return outstring[instring.find(l)]

def get_output(s):
	o = ''
	for l in s:
		o = o + get_output_l(l)
	return o

input = open('./sample.txt', 'r')
output = open('./output.txt', 'w')
case = int(input.readline())
for i in range(case):
	s = input.readline()
	s = s.replace('\n', '')
	o = get_output(s)
	print 'Case #{0}: {1}'.format(i+1,o)
	output.write('Case #{0}: {1}\n'.format(i+1,o))