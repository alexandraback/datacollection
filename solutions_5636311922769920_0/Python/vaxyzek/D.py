import gcj

ifile, ofile = gcj.get_files('D')

T = int(ifile.readline().strip())
for t in range(T):
	K, C, S = map(int, ifile.readline().strip().split(' '))
	ans = ' '.join(map(str, range(1, K + 1)))
	gcj.print_answer(ofile, t, ans)