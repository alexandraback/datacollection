import os,sys,fileinput

test_index = -1
valid_results = [ [0,0,0],[0,0,-1],[0,-1,-1],[0,-1,-2], [0,-2,-2] ]
for line in fileinput.input():
	test_index+=1
	if test_index == 0:
		continue
	line = line[:-1]
	numbers = [int(x) for x in line.split(" ") ]
	
	it = numbers.__iter__()
	N = it.next()
	S = it.next()
	p = it.next()

	t= []

	# print "-"*30
	# print "N:",N
	# print "S:",S
	# print "p:",p
	result = 0
	for i in range(N):
		x = it.next()
		t.append( x )
		p1 = p - 1
		p2 = p - 2

		if x >= 3*p:
			result += 1
		elif p1 >= 0 and x >= 2*p1 + p:
	# 		print "x is good", x
			result += 1
		elif p2 >=0 and x >= 2*p2 + p and S > 0:
	# 		print "x requires S", x, S
			result += 1
			S -= 1
		else:
	# 		print "x is low", x
			pass

	print "Case #%d: %d" % (test_index, result)
