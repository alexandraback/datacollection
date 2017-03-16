import math

def pal(num):
	for i in range(len(num)/2 + 1):
		if num[i] != num[-(i+1)]:
			return False
	return True

def fair_and_square(num):
	if not pal(num):
		#print "Not pal"
		return False
	sqrt_root = math.sqrt(int(num))
	if (sqrt_root - int(sqrt_root)) != 0:
		#print "not a square"
		return False
	if not pal(str(int(sqrt_root))):
		#print "not square of pal"
		return False
	return True

print fair_and_square('484')

h = open("Fair_and_Square.txt")
f_s = h.read()
f_s = f_s.split()

f = open("C-large-1.in")
g = open("Output.txt", 'w')

cases = int(f.readline())
for case in range(cases):
	ranges = f.readline()
	A, B = ranges.split()
	total = 0
	i = 0
	while int(f_s[i]) <= int(B):
		if int(f_s[i]) >= int(A):
			total += 1
		i += 1
		if i==len(f_s):
			break
	g.write("Case #" + str(case+1) + ": " + str(total) + "\n")


