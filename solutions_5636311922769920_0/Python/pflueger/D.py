# Date: 8 April 2016
# Comments: 

import time,sys,os.path,datetime

def do_case(case_number=0,inf=sys.stdin,outf=sys.stdout):
	k,c,s = map(int,inf.readline().split())
	if k==1:
		outf.write('Case #%d: 1\n'%case_number)
		return
	if (s*c < k):
		outf.write('Case #%d: IMPOSSIBLE\n'%case_number)
		return
	outf.write("Case #%d:" % (case_number) )
	for i in xrange( (k+c-1)/c ):
		digits = [ (c*i + j)%k for j in xrange(c) ]
		guess = sum([ (k**j)*digits[j] for j in xrange(c)])+1
		outf.write(' %d'%guess)
	outf.write('\n')

# PROBLEM-NONSPECIFIC TEMPLATE CODE FOLLOWS.
# This template version created 3 April 2016.
# The code below reads the input, and prints the output either to stdout or to a file.
# If output goes to a file, it also writes a log file for later reference.
# Notes:
# 	- If no arguments are provided, the program reads from standard input and prints to standard output.
# 	- The first argument specifies the input file name. If it is "x", the standard input is used.
# 	- The second argument specifies the output file name. If it is "a", an unused filename is created.
# 	- This code assumes that the first line of the input is the number of cases that follow.
# 	- If output is written to a file, then a corresponding "log" file is also created, to store some basic information and the source code used to create this output.

logf = None
#Print a message to standard error (for debugging)
def err(message,ending = "\n"):
	sys.stderr.write(str(message) + ending)
	if logf != None: logf.write(str(message) + ending)

def do_all_cases(inf=sys.stdin,outf=sys.stdout):
	T = int(inf.readline())
	err("There are %d cases."%T)
	start = time.time()
	cur = start
	prev = start
	for t in range(1,T+1):
		do_case(t,inf,outf)
		prev = cur
		cur = time.time()
		err("_%d(%d)_"%(t,int(1000*(cur-prev))),"")
	err("\nFinished %d cases in %d milliseconds."%(T,int(1000*(cur-start))))

def main_wrapper():
	if len(sys.argv) >= 2 and sys.argv[1] != 'x':
		inf = open(sys.argv[1])
	else:
		inf = sys.stdin
	if len(sys.argv) >= 3:
		outfname = sys.argv[2]
		logfname = sys.argv[2] + ".log"
		if sys.argv[2] == 'a':
			i = 0
			stem = sys.argv[1]
			# Remove ".in" from stem if present.
			if stem[-3:] == '.in': stem = stem[:-3]
			while os.path.isfile('%s.out%d'%(stem,i)): i += 1
			outfname = '%s.out%d'%(stem,i)
			logfname = '%s.log%d'%(stem,i)
		outf = open(outfname,'w')
		global logf 
		logf = open(logfname,'w')
		logf.write( str(datetime.datetime.now()) + '\n' )
		err('Writing output to %s.'%(outfname))
				
	else:
		outf = sys.stdout
	do_all_cases(inf,outf)
	if logf != None: # Print the source code, without template, for reference
		logf.write('\nSource code for %s:\n'%__file__)
		src = open(__file__)
		while True:
			line = src.readline()
			if line[:21] == '# PROBLEM-NONSPECIFIC': break
			logf.write(line)
		logf.write("\n(Template code omitted)\n")


main_wrapper()
