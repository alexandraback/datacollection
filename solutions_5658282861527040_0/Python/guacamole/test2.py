infile = open('t.in', 'r')
fout = file('t.out', 'w')
def get_line():
	return infile.readline()

cases = int(get_line())



for q in range(cases):
	print q
	[A, B, K] = get_line().rstrip('\n').split(' ')
	A = int(A)
	B = int(B)
	K = int(K)-1
	options = 0
	for a in range(A):
		for b in range(B):
			if a&b <= K:
				options += 1
	fout.write("Case #"+str(int(q)+1)+': '+str(options)+'\n')