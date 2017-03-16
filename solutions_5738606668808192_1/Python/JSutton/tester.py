infile = open("C-outputA.out", "r")

temp = infile.readline()

def toBase(n, base):
	total = 0
	for character in range(0, len(n)):
		total += int(n[character])*(base**(len(n)-character-1))
	return total

for line in range(500):
	case = infile.readline()
	num, a, b, c, d, e, f, g, h, i = map(int, case.split())
	if toBase(str(num), 2)%a != 0:
		print("{0} 2".format(line))
	if toBase(str(num), 3)%b != 0:
		print("{0} 3".format(line))
	if toBase(str(num), 4)%c != 0:
		print("{0} 4".format(line))
	if toBase(str(num), 5)%d != 0:
		print("{0} 5".format(line))
	if toBase(str(num), 6)%e != 0:
		print("{0} 6".format(line))
	if toBase(str(num), 7)%f != 0:
		print("{0} 7".format(line))
	if toBase(str(num), 8)%g != 0:
		print("{0} 8".format(line))
	if toBase(str(num), 9)%h != 0:
		print("{0} 9".format(line))
	if toBase(str(num), 10)%i != 0:
		print("{0} 10".format(line))