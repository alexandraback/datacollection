import fileinput
stdin = fileinput.input()

# Does chooser (Richard) win?
def solveCase():
	X,R,C = map(int,stdin.next().split())
	if C<R:
		R,C = C,R
	# R<=C
	if R*C%X!=0:
		return True
	if X==1:
		return False
	if X==2:
		return False
	if X==3:
		if C<=4:
			return R==1
	if X==4:
		if C<=3:
			return True
		if C==4:
			return R<=2
	# if X>=2*C+1 or X>=7:
	# 	return True


for case in xrange(int(stdin.next())):
	print "Case #{0}: {1}".format(case+1,"RICHARD" if solveCase() else "GABRIEL")