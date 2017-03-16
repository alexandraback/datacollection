fout = open("out.txt", "w")

n = 16
j = 50

found = 0
number = "1" + ((n-2)*"0") + "1"

def getDivison(nr, base):
	realNr = int(nr, base)
	for x in xrange(2, 1000):
		if realNr % x == 0:
			return x
	return 0


fout.write("Case #1:\n")
while found < j:
	dividers = ""
	correct = True
	for x in xrange(2, 11):
		divider = getDivison(number, x)
		if divider == 0:
			correct = False
			break
		else:
			dividers += " " + str(divider)

	if correct:
		fout.write("%s%s\n" % (number, dividers))
		print "%s%s" % (number, dividers)
		found += 1

	number = "{0:b}".format(int(number[0:-1], 2) + 1) + "1"



fout.close()