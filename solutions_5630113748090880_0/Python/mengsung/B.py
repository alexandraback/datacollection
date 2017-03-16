
def solve():

	n = int(input())
	pos = [0] * 2501
	row = [] 
	
	for i in range(2*n - 1):
		line = [int(x) for x in input().split()]
		for x in line:
			pos[x] += 1
	
	for i in range(len(pos)):
		if pos[i] % 2 == 1:
			row.append(i)
	
	s = ''
	for i in row:
		s += '{} '.format(i)
	return s
	
		

if __name__ == '__main__':
	ncase = int(input())
	for i in range(ncase):
		print('Case #{}: {}'.format(i+1, solve()))
