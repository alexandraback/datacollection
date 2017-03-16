array = []
with open("A-small-attempt0.in", "r") as ins:
    for line in ins:
        array.append(line)

for b in range(1, len(array)):
	string = array[b]
	z = 0
	w = 0
	u = 0
	x = 0
	g = 0
	o = 0
	t = 0
	f = 0
	s = 0
	i = 0
	for c in string:
		if c == "Z":
			z += 1
		if c == "W":
			w += 1
		if c == "U":
			u += 1
		if c == "X":
			x += 1
		if c == "G":
			g += 1
		if c == "O":
			o += 1
		if c == "T":
			t += 1
		if c == "F":
			f += 1
		if c == "S":
			s += 1
		if c == "I":
			i += 1
	o -= z
	o -= w
	o -= u
	t -= w
	t -= g
	f -= u
	s -= x
	i -= g
	i -= x
	i -= f
	final = ""
	for j in range(0, z):
		final += "0"
	for j in range(0, o):
		final += "1"
	for j in range(0, w):
		final += "2"
	for j in range(0, t):
		final += "3"
	for j in range(0, u):
		final += "4"
	for j in range(0, f):
		final += "5"
	for j in range(0, x):
		final += "6"
	for j in range(0, s):
		final += "7"
	for j in range(0, g):
		final += "8"
	for j in range(0, i):
		final += "9"
	print("Case #" + str(b) + ": " + final)



