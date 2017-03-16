T = int(raw_input())

#def func(rr):
#	if len(rr) == 0:
#		return ""
#	if len(rr) == 1:
#		return rr
#	m = max(rr)
#	num = rr.count(m)
#	new = rr.split(m)
#	out = num * m
#	for ii in new:
#		out += func(ii)
#	return out

def func(rr):
	if len(rr) <= 1:
		return rr
	x = list(rr)
	curr = x[0]
	for i in xrange(1,len(x)):
		toadd = x[i]
		if toadd >= curr[0]:
			curr = toadd + curr
		else:
			curr = curr + toadd
	return curr

def doprob():
	read = str(raw_input())
	return func(read)

for qq in xrange(T):
	print "Case #" + str(qq+1) + ": " + str(doprob())