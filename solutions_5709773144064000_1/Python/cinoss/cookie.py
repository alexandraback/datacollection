import sys
fname = "B-small-attempt0.in"
fname = "B-large.in"
# fname = "sample.in"
fi = open(fname)
fo = open("fo.txt","w")
for test in range(int(fi.readline())):
	c,f,x = [float(x) for x in fi.readline().strip().split()]
	bt = 0
	min_t = sys.float_info.max	
	v = 2.0
	while bt < min_t:
		t = bt + x/v
		# print t
		if t < min_t:
			min_t = t
		bt += c/v
		v += f
	print >>fo,"Case #%d: %.7f"%(test+1, min_t)

