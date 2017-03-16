infile = open('C-small-attempt5.in', 'r')
outfile = open('test.out', 'w')

T = int(infile.readline())

for t in range(1, T+1):
	J, P, S, K = map(int, infile.readline().split(' '))

	jp_table = [[0]*P for j in range(J)]
	ps_table = [[0]*S for p in range(P)]
	sj_table = [[0]*J for s in range(S)]

	s_lst = []
	tmp = range(1, min(S+1, K+1))
	for s in range(P):
		s_lst += tmp
		tmp = tmp[1:] + [tmp[0]]

	lst = []
	for j in range(1, J+1):
		for p in range(1, P+1):
			for s in range(len(s_lst)):
				if (j, p, s_lst[s]) not in lst:
					lst.append((j, p, s_lst[s]))

	outfile.write('Case #' + str(t) + ': ' + str(len(lst)) + '\n')
	for l in range(len(lst)):
		outfile.write(' '.join(map(str, lst[l])) + '\n')