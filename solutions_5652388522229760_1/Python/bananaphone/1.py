T = int(raw_input())

def doprob():
	read = int(raw_input())
	if read == 0:
		return "INSOMNIA"
	current = 0
	tofix = list(xrange(10))
	while tofix:
		current += read
		toremove = []
		for x in tofix:
			if str(x) in str(current):
				toremove.append(x)
		for x in toremove:
			tofix.remove(x)
	return current

for qq in xrange(T):
	print "Case #" + str(qq+1) + ": " + str(doprob())