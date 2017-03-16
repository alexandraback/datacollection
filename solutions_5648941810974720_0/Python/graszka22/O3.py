import sys
def ct(s):
	r = 26*[0]
	for c in s:
		if not c.isalpha(): continue
		r[ord(c)-ord('A')] += 1
	return r

def minus(l1, l2):
	for x in xrange(26):
		if l1[x] < l2[x]:
			return False
	for x in xrange(26):
		l1[x] -= l2[x]

	return True

k = [6, 8, 3, 4, 5, 0, 7, 2, 1, 9]
z = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

t = int(raw_input())

for x in xrange(t):
	l = ct(raw_input())
	d = 10*[0]	
	for y in xrange(10):
		while minus(l, ct(z[k[y]])):
			d[k[y]] += 1
	sys.stdout.write("Case #"+str(x+1)+": ")
	for y in xrange(10):
		sys.stdout.write("".join(d[y]*[str(y)]))
	sys.stdout.write("\n")
 
			
	
	
