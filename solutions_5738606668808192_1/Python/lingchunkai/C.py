# small
# N = 16
# J = 50

# large
N = 32
J = 500

n = N-2 # assume n is even
# choose one odd and one even
dd = []
for j in xrange(J):
	i = format(j, "0" + str(n/2) +"b")
	# interweave
	d = ""
	for ii in i:
		d += ii + ii
	dd.append("1" + d + "1")

print "Case #1:"
for d in dd:
	for b in xrange(2,10):
		x = 0
		for i,z in enumerate(d):
			# print i,z
			if z == '1': x += b ** i
		# print x
		assert(x%(b+1)==0)
	print d + " 3 4 5 6 7 8 9 10 11"



