import os,sys,fileinput

test_index = -1

for line in fileinput.input():
	test_index+=1
	if test_index == 0:
		continue
	line = line[:-1]
	[A,B] = [ int(x) for x in line.split(" ") ]
	
	result = 0
	found = {}
	for n in range(A,B):
		s=str(n)
		digits = len(s)
		for i in range(digits):
			s = "%c%s" % ( s[-1] , s[:-1] ) 
			m = int( s )
			if m > n and m <= B:
				k = (n,m)
				if not k in found:
					# print n,m
					result+=1
					found[k] = 1

	print "Case #%d: %d" % (test_index, result)
