
def digits(n):
	dig = []
	n = list(n)
	while("W" in n):
		n.remove("T")
		n.remove("W")
		n.remove("O")
		dig.append(2)
	while("Z" in n):
		n.remove("Z")
		n.remove("E")
		n.remove("R")
		n.remove("O")
		dig.append(0)
	while("X" in n):
		n.remove("S")
		n.remove("I")
		n.remove("X")
		dig.append(6)
	while("U" in n):
		n.remove("F")
		n.remove("O")
		n.remove("U")
		n.remove("R")
		dig.append(4)
	while("F" in n):
		n.remove("F")
		n.remove("I")
		n.remove("V")
		n.remove("E")
		dig.append(5)
	while("V" in n):
		n.remove("S")
		n.remove("E")
		n.remove("V")
		n.remove("E")
		n.remove("N")
		dig.append(7)
	while("G" in n):
		n.remove("E")
		n.remove("I")
		n.remove("G")
		n.remove("H")
		n.remove("T")
		dig.append(8)
	while("O" in n):
		n.remove("O")
		n.remove("N")
		n.remove("E")
		dig.append(1)
	while("I" in n):
		n.remove("N")
		n.remove("I")
		n.remove("N")
		n.remove("E")
		dig.append(9)
	while("H" in n):
		n.remove("T")
		n.remove("H")
		n.remove("R")
		n.remove("E")
		n.remove("E")
		dig.append(3)
	dig.sort()
	dig = list(dig)
	return ''.join(str(e) for e in dig)

f = open('A-large.in.txt', 'r')
f2 = open('outputLarge.txt', 'w')
final = ''

for i in range(1, int(f.readline().strip())+1):
	s = f.readline().strip()
	final += 'Case #{}: {}\n'.format(i, digits(s))

f2.write(final)
