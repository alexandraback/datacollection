import gcj

ifile, ofile = gcj.get_files('A')

T = int(ifile.readline().strip())
for t in range(T):
	N = int(ifile.readline().strip())
	ans = "INSOMNIA"
	if N != 0:
		digits = [0] * 10
		i = 1
		while min(digits) == 0:
			NN = i * N
			while NN > 0:
				digit = NN % 10
				digits[digit] = 1
				#print(NN, digit)
				NN //= 10
			i += 1
			#print(digits)
		ans = (i - 1) * N

	gcj.print_answer(ofile, t, ans)