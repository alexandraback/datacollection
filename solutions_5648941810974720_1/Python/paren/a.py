from sys import stdin, stdout
t = int(stdin.readline())
for j in range(1, t+1):
	s = stdin.readline().strip()
	ans = []
	
	z = s.count("Z")
	ans.extend([0]*z)
	for i in range(z):
		s = s.replace("Z", "",1)
		s = s.replace("E", "",1)
		s = s.replace("R", "",1)
		s = s.replace("O", "",1)
	
	z = s.count("W")
	ans.extend([2]*z)
	for i in range(z):
		s = s.replace("T", "",1)
		s = s.replace("W", "",1)
		s = s.replace("O", "",1)
	
	z = s.count("X")
	ans.extend([6]*z)
	for i in range(z):
		s = s.replace("S", "",1)
		s = s.replace("I", "",1)
		s = s.replace("X", "",1)
	
	z = s.count("S")
	ans.extend([7]*z)
	for i in range(z):
		s = s.replace("S", "",1)
		s = s.replace("E", "",2)
		s = s.replace("V", "",1)
		s = s.replace("N", "",1)
	
	z = s.count("V")
	ans.extend([5]*z)
	for i in range(z):
		s = s.replace("F", "",1)
		s = s.replace("I", "",1)
		s = s.replace("V", "",1)
		s = s.replace("E", "",1)
	
	z = s.count("G")
	ans.extend([8]*z)
	for i in range(z):
		s = s.replace("E", "",1)
		s = s.replace("I", "",1)
		s = s.replace("G", "",1)
		s = s.replace("H", "",1)
		s = s.replace("T", "",1)
	
	z = s.count("U")
	ans.extend([4]*z)
	for i in range(z):
		s = s.replace("F", "",1)
		s = s.replace("O", "",1)
		s = s.replace("U", "",1)
		s = s.replace("R", "",1)
	
	z = s.count("I")
	ans.extend([9]*z)
	for i in range(z):
		s = s.replace("N", "",2)
		s = s.replace("I", "",1)
		s = s.replace("E", "",1)
	
	z = s.count("N")
	ans.extend([1]*z)
	for i in range(z):
		s = s.replace("O", "",1)
		s = s.replace("N", "",1)
		s = s.replace("E", "",1)
	
	z = s.count("T")
	ans.extend([3]*z)
	for i in range(z):
		s = s.replace("T", "",1)
		s = s.replace("H", "",1)
		s = s.replace("R", "",1)
		s = s.replace("E", "",2)
	ans.sort()
	stdout.write("Case #"+str(j)+": "+"".join(map(str, ans)) + "\n")
	