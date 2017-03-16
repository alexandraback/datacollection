import argparse

parser =  argparse.ArgumentParser(description='Google Code Jam 2016')
parser.add_argument('fin')
parser.add_argument('fout')

args = parser.parse_args()

fin = args.fin
fout = args.fout

def rank_and_file(N,A):
	count = {}
	for i in range(0,N*2-1):
		for j in range(0,N):
			print(A[i][j])
			if A[i][j] not in count:
				count[A[i][j]] = 1
			else:
				count[A[i][j]] = count[A[i][j]] + 1

	ret = []

	for i in count:
		print('{} {}'.format(i,count[i]))
		if count[i] % 2 == 1:
			ret.append(i)
			print(ret)
	ret.sort()
	ret_string = [str(i) for i in ret]
	
	return ' '.join(ret_string)

with open(fin,'r') as input, open(fout,'w') as output:
	T = int(input.readline().rstrip('\n'))
	for i in range(0,T):
		s = input.readline().rstrip('\n')
		N = int(s)
		A = []
		for j in range(0, 2*N-1):
			l = input.readline().rstrip('\n').split(' ')
			l = [int(h) for h in l]
			A.append(l)
			print(A)
		output.write('Case #{}: {}\n'.format(i+1,rank_and_file(N,A)))