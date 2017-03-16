import sys
def fun(word):
	w=str(word[0])
	for i in range(1, len(word)):
		if ord(word[i]) >= ord(w[0]):
			w=word[i]+w
		else:
			w=w+word[i]
	return w

lines=sys.stdin.readlines()
n=int(lines[0])
for i in range(1,n+1):
	print "Case #%d: %s" % (i, fun(lines[i].strip()))
