import sys
n = int(raw_input())
d = {'a': 'y', 'c': 'e', 'b': 'h', 'e': 'o', 'd': 's', 'g': 'v', 'f': 'c', 'i': 'd', 'h': 'x', 'k': 'i', 'j': 'u', 'm': 'l', 'l': 'g', 'o': 'k', 'n': 'b', 'p': 'r', 's': 'n', 'r': 't', 'u': 'j', 't': 'w', 'w': 'f', 'v': 'p', 'y': 'a', 'x': 'm', 'z': 'q', 'q': 'z'}
words = []
for i in xrange(n):
	b = False
	sys.stdout.write("Case #" + str(i+1) + ": ")
	for word in raw_input().split(" "):
		if b:
			sys.stdout.write(" ")
		for char in word:
			sys.stdout.write(d[char])
		b = True
	sys.stdout.write("\n")
