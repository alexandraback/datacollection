import argparse

parser =  argparse.ArgumentParser(description='Google Code Jam 2016')
parser.add_argument('fin')
parser.add_argument('fout')

args = parser.parse_args()

fin = args.fin
fout = args.fout

def last_num(n):
	s = set(range(0,10))
	if n==0:
		return 'INSOMNIA'
	else:
		i = 1
		while(True):
			s = s - num2set(n*i)
			if len(s) == 0:
				return n*i
			i += 1


def num2set(n):
	s = set()
	while(n>0):
		s.add(n % 10)
		n = n//10
	#print(s)
	return s



with open(fin,'r') as input, open(fout,'w') as output:
	T = int(input.readline().rstrip('\n'))
	for i in range(0,T):
		s = input.readline().rstrip('\n')
		n = int(s)
		#print('Case #{}: {}\n'.format(i+1,last_num(n)))
		output.write('Case #{}: {}\n'.format(i+1,last_num(n)))