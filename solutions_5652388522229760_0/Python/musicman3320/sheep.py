fin = open('A-small-attempt0.in', 'r')
fout = open('A-small-attempt0.out','w')


numlines = int(fin.readline().rstrip())

for i in range(numlines):
	val = int(fin.readline().rstrip())
	result = "INSOMNIA"
	if val > 0:
		result = 0
		digits = [False]*10
		while(not(all(digits))):
			result = result + val
			for c in str(result):
				digits[int(c)] = True
	
	outstr = "Case #" + str(i+1) + ": " + str(result) + "\n"
	# print outstr.rstrip()
	fout.write(outstr)


