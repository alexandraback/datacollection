key = {'a': 'y', 'b': 'h', 'c': 'e', 'd': 's', 'e': 'o', 'f': 'c', 'g': 'v', 'h': 'x', 'i': 'd', 'j': 'u', 'k': 'i', 'l': 'g', 'm': 'l', 'n': 'b', 'o': 'k', 'p': 'r', 'q': 'z', 'r': 't', 's': 'n', 't': 'w', 'u': 'j', 'v': 'p', 'w': 'f', 'x': 'm', 'y': 'a', 'z': 'q', }
fin = open("A-small.in", "r")
fout = open("A-small.out", "w")
n = int(fin.readline())
for i in range(n):
	s = fin.readline()[:-1]
	ans = ''
	for x in s:
		if x == ' ':
			ans += ' '
		else:
			ans += key[x]
	fout.write("Case #%d: %s\n" % (i+1, ans))
