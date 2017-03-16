import sys, traceback

def strategyOne(A, B, pi):
	allCorrect = reduce(lambda x,y: x*y, pi)
	return (B-A+1)*allCorrect + (2*B-A+2)*(1-allCorrect)

def strategyTwo(A, B, pi, nbs):
	remainCorrect = reduce(lambda x,y: x*y, pi[:A-nbs])
	return (2*nbs + B - A + 1) * remainCorrect + (2*nbs + 2*B - A + 2) * (1 - remainCorrect)

def strategyThree(A, B, pi):
	return float(B + 2)

def evalEachCase (A, B, pi):
	exp = []
	exp.append(strategyOne(A, B, pi))
	for nbs in range(A):
		exp.append(strategyTwo(A, B, pi, nbs))
	exp.append(strategyThree(A, B, pi))
	minexp = min(exp)
	return "%.6f" % minexp

def main ():
	dir = "C:/Users/Firman/Documents/Programming/Python/GoogleCodeJam/2012/Round1A/"
	fin = open (dir+"A-small-attempt0.in", "r") # nama file input
	fout = open (dir+"A-small-attempt0.out", "w") # nama file output
	
	content = fin.read()
	lines = content.split('\n')
	
	T = eval(lines.pop(0))
	
	linesOut = []
	for i in range (T):
		line = lines.pop(0)
		args = line.split()
		A = eval(args.pop(0))
		B = eval(args.pop(0))
		
		args = lines.pop(0).split()
		pi = []
		for j in range(A):
			pi.append(float(eval(args.pop(0))))
		linesOut.append ("Case #" + str(i+1) + ": " + evalEachCase (A, B, pi) )
	
	contentOut = "\n".join(linesOut)
	fout.write(contentOut)
	
	fin.close()
	fout.close()

try:
	main()
	print "Success"
	raw_input()
except:
	exc_type, exc_value, exc_traceback = sys.exc_info()
	print traceback.print_tb(exc_traceback)
	print traceback.print_exception(exc_type, exc_value, exc_traceback)
	raw_input()
