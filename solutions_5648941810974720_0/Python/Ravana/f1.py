
T = int(input()) # cases

for i in range(T):
	out = []
	s = list(input())
	while("Z" in s):
		out.append("0")
		s.remove("Z")
		s.remove("E")
		s.remove("R")
		s.remove("O")
	while("X" in s):
		out.append("6")
		s.remove("S")
		s.remove("I")
		s.remove("X")
	while("W" in s):
		out.append("2")
		s.remove("T")
		s.remove("W")
		s.remove("O")
	while("G" in s):
		out.append("8")
		s.remove("E")
		s.remove("I")
		s.remove("G")
		s.remove("H")
		s.remove("T")
	while("S" in s):
		out.append("7")
		s.remove("S")
		s.remove("E")
		s.remove("V")
		s.remove("E")
		s.remove("N")
	while("H" in s):
		out.append("3")
		s.remove("T")
		s.remove("H")
		s.remove("R")
		s.remove("E")
		s.remove("E")
	while("V" in s):
		out.append("5")
		s.remove("F")
		s.remove("I")
		s.remove("V")
		s.remove("E")
	while("F" in s):
		out.append("4")
		s.remove("F")
		s.remove("O")
		s.remove("U")
		s.remove("R")
	while("O" in s):
		out.append("1")
		s.remove("O")
		s.remove("N")
		s.remove("E")
	while("N" in s):
		out.append("9")
		s.remove("N")
		s.remove("I")
		s.remove("N")
		s.remove("E")
	# print(s)
	print("Case #"+str(i+1)+":","".join(sorted(out)))
	# print(out)


