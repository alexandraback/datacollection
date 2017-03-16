import argparse

parser =  argparse.ArgumentParser(description='Google Code Jam 2016')
parser.add_argument('fin')
parser.add_argument('fout')

args = parser.parse_args()

fin = args.fin
fout = args.fout

def num_of_flips(s):
	s = clean_input(s)
	print(s)
	print(len(s))
	ret = len(s)-1
	if s[-1] == '-':
		ret += 1
	return ret

def clean_input(s):
	ret = ''
	last = '*'
	for c in s:
		if c != last:
			ret += c
			last = c
	return ret

with open(fin,'r') as input, open(fout,'w') as output:
	T = int(input.readline().rstrip('\n'))
	for i in range(0,T):
		s = input.readline().rstrip('\n')
		output.write('Case #{}: {}\n'.format(i+1,num_of_flips(s)))