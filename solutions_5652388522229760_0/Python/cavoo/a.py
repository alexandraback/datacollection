def readint():
	return int(input())

def extend_set(s, b):
	for x in b:
		s.add(x)
	return s
	
def last_number(n):
	seen = set()
	for i in range(1, 1000):
		extend_set(seen, str(n * i))
		if len(seen) == 10:
			return str(n * i)
	return "INSOMNIA"

def main():
	N = readint()

	for t in range(1, N + 1):
		n = readint()
		print("Case #%d: %s" % (t, last_number(n)))
		
main()
