f = open("a.in")
d = f.read().strip().split("\n")[1:]
f.close()

o = open("a.out", "w")
for i in xrange(len(d)):
	s = d[i]
	s = list(s)
	ds = []
	
	while "Z" in s:
		del s[s.index("Z")]
		del s[s.index("E")]
		del s[s.index("R")]
		del s[s.index("O")]
		ds.append(0)
	
	while "W" in s:
		del s[s.index("T")]
		del s[s.index("W")]
		del s[s.index("O")]
		ds.append(2)
	
	while "X" in s:
		del s[s.index("S")]
		del s[s.index("I")]
		del s[s.index("X")]
		ds.append(6)
	
	while "G" in s:
		del s[s.index("E")]
		del s[s.index("I")]
		del s[s.index("G")]
		del s[s.index("H")]
		del s[s.index("T")]
		ds.append(8)
	
	while "S" in s:
		del s[s.index("S")]
		del s[s.index("E")]
		del s[s.index("V")]
		del s[s.index("E")]
		del s[s.index("N")]
		ds.append(7)
	
	while "H" in s:
		del s[s.index("T")]
		del s[s.index("H")]
		del s[s.index("R")]
		del s[s.index("E")]
		del s[s.index("E")]
		ds.append(3)
	
	while "V" in s:
		del s[s.index("F")]
		del s[s.index("I")]
		del s[s.index("V")]
		del s[s.index("E")]
		ds.append(5)
	
	while "F" in s:
		del s[s.index("F")]
		del s[s.index("O")]
		del s[s.index("U")]
		del s[s.index("R")]
		ds.append(4)
	
	while "O" in s:
		del s[s.index("O")]
		del s[s.index("N")]
		del s[s.index("E")]
		ds.append(1)
	
	while "N" in s:
		del s[s.index("N")]
		del s[s.index("I")]
		del s[s.index("N")]
		del s[s.index("E")]
		ds.append(9)
	
	ds.sort()
	ds = "".join(map(str, ds))
	
	ln = "Case #%d: %s" % (i + 1, ds)
	print ln
	o.write(ln + "\n")
o.close()
