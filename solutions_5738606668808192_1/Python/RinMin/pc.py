from sys import *
from math import *

def get_divisor(i):
	lim = int(min(1000, sqrt(i)))
	for c in range(2, int(lim+1)):
		if i % c == 0:
			return c
	return 1

def candidates(n):
	if n == 2:
		yield "11"
	f = "{0:0" + str(n-2) + "b}"
	for i in range(0, int(pow(2, n-2))):
		yield "1" + f.format(i) + "1"

def calc_value(n, base):
	value = 0
	i = 1
	for d in reversed(n):
		if d == '1':
			value = value + i
		i = i * base
	return value


fin = open(argv[1] + ".in", 'r') 
fout = open(argv[1] + ".out", 'w')

fin.readline()
values = fin.readline().split(" ")

width = int(values[0])
num = int(values[1])

fout.write("Case #1:\n")

num_found = 0
for c in candidates(width):
	if num_found == num:
		break
	line = c
	for base in range(2, 12):
		if base == 11:
			for b in range(2, 11):
				val = calc_value(c, b)
				div = get_divisor(val)
				#print("  Base " + str(b) + ": " + str(val) + "/" + str(div) + "=" + str(val/div))
			fout.write(line + "\n")
			num_found = num_found + 1
			print(str(num_found) + ": " + line)
		else:
			val = calc_value(c, base)
			div = get_divisor(val)
			if div == 1:
				# It's a prime, stop the case
				break
			else:
				line = line + " " + str(div)

fin.close()
fout.close()


	
