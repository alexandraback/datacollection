from sys import *

def digit_array():
	digits = []
	for d in range(0, 10):
		digits.append(False)
	return digits

def check_digits(n):
	digits = digit_array()
	while n > 0:
		digits[n%10] = True
		n = int(n/10)
	return digits

def calc_case(n):
	if n == 0:
		return "INSOMNIA"

	i = 1
	seen_digits = digit_array()
	while True:
		digits = check_digits(n*i)
		for d in range(0, 10):
			seen_digits[d] = seen_digits[d] or digits[d]

		seen_all = True
		for d in range(0, 10):
			if seen_digits[d] == False:
				seen_all = False
				break
		if seen_all:
			return str(i*n)
		else:
			i = i + 1

fin = open(argv[1] + ".in", 'r') 
fout = open(argv[1] + ".out", 'w')

ncases = int(fin.readline())
for c in range(0, ncases):
	fout.write("Case #" + str(c+1) + ": " + calc_case(int(fin.readline())) + "\n")

fin.close()
fout.close()


	
