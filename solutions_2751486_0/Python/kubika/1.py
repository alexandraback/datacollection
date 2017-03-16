
def iscons(x):
	if x == 'a' or x == 'e' or x == 'i' or x == 'o' or x == 'u':
		return False
	return True

def consonants(n, name):
	y = 0
	while y <= (len(name) - n):
		counter = 0
		for x in xrange(n):
			if iscons(name[x + y]):
				counter = counter + 1;
		if counter == n:
			return True
		y = y + 1
   	return False



f = open("A-small-attempt0.in", 'r')
g = open("output.out", 'w')
cases = int(f.readline())
i = 0

while i<cases:

 	i = i+1
	z = f.readline()
	name = (z.split()[0])
	n = int(z.split()[1])

	counter = 0
	x = 0
	while x <= (len(name) - n):
		y = x + n
		while y <= len(name):
			if consonants(n, name[x:y]):
				counter = counter + 1
			y = y + 1
		x = x + 1

	g.write("Case #" + str(i) + ": " + str(counter) + "\n")






	
