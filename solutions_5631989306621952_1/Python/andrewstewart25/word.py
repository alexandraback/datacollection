import sys
def f(s):

	out = ''

	for c in s:

		if not out:

			out = c

			continue

		if c >= out[0]:

			out = c + out

		else:

			out = out + c

	return out


	
count = 0
total = None
for line in sys.stdin:
	line = line.strip()
	if (total == None):
		total = int(line)
		continue
	count += 1
	print "Case #%s: %s"%(count,f(line))
	if count == total:
		break