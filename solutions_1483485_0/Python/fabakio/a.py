import sys

def main():
	fp = open('A-small-attempt0.in', 'r')

	frases = [
		"ejp mysljylc kd kxveddknmc re jsicpdrysi",
		"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
		"de kr kd eoya kw aej tysr re ujdr lkgc jv",
	]

	paratraduzir = [
		"our language is impossible to understand",
		"there are twenty six factorial possibilities",
		"so it is okay if you want to just give up",
	]

	table = {}
	for x in xrange(len(frases)):
		for y in xrange(len(frases[x])):
			table[frases[x][y]] = paratraduzir[x][y]
	
	table['q'] = 'z'
	table['z'] = 'q'

	fp.readline()

	n = 1
	for line in fp.readlines():
		sys.stdout.write("Case #")
		sys.stdout.write(str(n))
		sys.stdout.write(": ")
		line = line.strip()
		for c in line:
			sys.stdout.write(table[c])
		print
		n+=1

if __name__ == "__main__":
	main()

