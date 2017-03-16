def test(d, f):
	for i in range(len(d)):
		if f[i] == "0":
			a = False
			b = False
			for j in range(len(d)):
				if d[i][0] == d[j][0] and f[j] == "1":
					a = True
				if d[i][1] == d[j][1] and f[j] == "1":
					b = True
			if a == False or b == False:
				return False
	return True
					

def solve(d):
	big = 0
	n = len(d)
	for i in range(0, 2**n):
		f= (("0"*16) + bin(i)[2:])[-n:]
		if f.count("0") <= big:
			continue
		if test(d, f):
			if f.count("0") > big:
				big = f.count("0")
	return big
		


CASES = int(raw_input())

case = 1
for i in range(CASES):
	p = int(raw_input())
	d = []
	for i in range(p):
		d.append(raw_input().split())
	#print d
	print ("Case #%d:" % case), solve(d)
	case += 1
