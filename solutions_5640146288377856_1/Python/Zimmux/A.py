import fileinput
stdin = fileinput.input()

def solveCase():
	R,C,W = map(int,stdin.next().split())
	return (R-1)*(C//W) + (C-1)//W+W

for case in xrange(int(stdin.next())):
	print "Case #{0}: {1}".format(case+1,solveCase())