


from itertools import product
from string import ascii_lowercase

def equal (a, b):
	if len(a) != len(b): return False
	for i in range (len(a)):
		if a[i] != '?' and a[i] != b[i]:
			return False
	return True

l = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]

n = int(raw_input())
t = 1

while n != 0:
	a, b  = raw_input().split()
	keywords = [''.join(i) for i in product(l, repeat = len(a))]
	ra = ""
	rb = ""
	diff = 1000000000
	for i in keywords:
		for j in keywords:
			if equal(a, i) and equal(b, j):
				A = int(i)
				B = int(j)
				if abs(A - B) < diff:
					diff = abs (A - B)
					ra = i
					rb = j
				if abs(A - B) == diff:
					if (ra == i):
						if (rb > j):
							rb = j	
					if (ra > i):
						ra = i
						rb = j
	print "Case #" + str(t) + ": " + ra + " " + rb
	t+=1		
	n -= 1
				
				
