import sys, traceback

def evalEachCase (N, to, frm):
	# mencari node tempat berangkat
	inits = []
	for node in to:
		if node not in frm: inits.append(node) # jika node adalah tempat berangkat
	
	for init in inits:
		marks = [0]*N
		queue = [init]
		while len(queue) > 0:
			prNode = queue.pop(0)
			print prNode
			if marks[prNode]: return "Yes"
			marks[prNode] = 1
			
			nextNodes = to[prNode]
			queue += nextNodes
	
	return "No"

def main ():
	dir = "C:/Users/Firman/Documents/Programming/Python/GoogleCodeJam/2012/Round1C/"
	fin = open (dir+"A-small-practice.in", "r") # nama file input
	fout = open (dir+"A-small-practice.out", "w") # nama file output
	
	content = fin.read()
	lines = content.split('\n')
	
	T = eval(lines.pop(0))
	
	linesOut = []
	for i in range (T):
		N = eval(lines.pop(0))
		to = {}
		frm = {}
		for j in range(N):
			args = [eval(arg)-1 for arg in lines.pop(0).split()]
			args.pop(0)
			to[j] = args[:]
			for arg in args:
				if arg not in frm: frm[arg] = [j]
				else: frm[arg].append(j)
		
		print "Attempting Case #" + str(i+1)
		linesOut.append ("Case #" + str(i+1) + ": " + evalEachCase (N, to, frm) )
	
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
