fin = open ("A-large.in", "r")
fout = open ("A-large.out", "w")

t = int(fin.readline())
for i in range (t):
	n = int(fin.readline())
		
	fout.write ("Case #{:d}: ".format(i + 1))
	if (n == 0): fout.write("INSOMNIA\n")
	else:
		bit = 0
		now = n
		while (bit + 1 != (1 << 10)):
			for c in str(now): bit |= 1 << int(c)
			now += n
			
		fout.write(str(now - n) + '\n')
		
fin.close()
fout.close()