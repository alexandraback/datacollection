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

f = open("C-small-attempt0.in")
cases = int(f.readline())
for case in range(cases):
	ranges = f.readline()
	A, B = ranges.split()
	total = 0
	for i in range(int(A),int(B)+1):
		if fair_and_square(str(i)):
			total += 1
	print "Case #" + str(case+1) + ": " + str(total)


