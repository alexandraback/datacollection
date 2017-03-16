import sys

def main():
	fp = open('C-large.in', 'r')
	fp.readline()
	
	n = 1
	for line in fp.readlines():
		result = 0
		line = line.strip().split(' ')
		a = int(line[0])
		b = int(line[1])
		
		while a < b:
			ja = {}
			l = len(str(a))
			c = a
			p = pow(10, l - 1)
			for x in xrange(l - 1, 0, -1):
				c = c / 10 + (c % 10) * p
				if a < c <= b and c not in ja:
					ja[c] = 1
					result += 1
			a += 1
			
		sys.stdout.write("Case #" + str(n) + ": " + str(result) + "\n")
		n+=1
		
if __name__ == "__main__":
	main()

