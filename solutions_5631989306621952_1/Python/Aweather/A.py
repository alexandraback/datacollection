import argparse

parser =  argparse.ArgumentParser(description='Google Code Jam 2016')
parser.add_argument('fin')
parser.add_argument('fout')

args = parser.parse_args()

fin = args.fin
fout = args.fout

def last_word(s):
	ret = s[0]
	for i in range(1,len(s)):
		if s[i] >= ret[0]:
			ret = s[i] + ret
		else:
			ret = ret + s[i]
	return ret



with open(fin,'r') as input, open(fout,'w') as output:
	T = int(input.readline().rstrip('\n'))
	for i in range(0,T):
		s = input.readline().rstrip('\n')
		
		
		#print('Case #{}: {}\n'.format(i+1,last_num(n)))
		output.write('Case #{}: {}\n'.format(i+1,last_word(s)))