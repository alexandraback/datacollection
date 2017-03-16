#Python

fn = open('radii_input_l.in','r')
T = int(fn.readline())
for i in range(T):
	line = fn.readline()
	vals = line.split(' ')
	r = int(vals[0])
	l = int(vals[1])
	tmp = 2 * r
	end = int(pow(l,0.5))
	start = 0
	while start <= end:
		index = int((start+end)/2)
		#print "index: " + str(index)
		cur = index * (2*index + tmp -1)
		#print "cur: " + str(cur)
		if cur > l:
			end = index - 1 
		else:
			start = index + 1
	if cur > l:
		index -= 1
	#print str(start) + "," + str(end) + "," + str(cur)
	print "Case #" + str(i+1) + ": " + str(index)
