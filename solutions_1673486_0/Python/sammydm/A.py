'''
+1 for "enter key pressed"
A := # of characters typed
B := # of characters in password
A real numbers that are probability correctly typed each character so far
output optimal expected number of keystrokes (within error of 10^-6)
'''

###########################################################
# function defs
###########################################################


###########################################################
# input
###########################################################

input_file = 'A-small-attempt0.in.txt'
#input_file = 'A-large.in.txt'
input_data = open(input_file,'r').readlines()

###########################################################
# cases
###########################################################

output = ''
num_cases = int(input_data[0])
i = 1
for n in range(num_cases):
	A = int(input_data[i].rstrip().split()[0])
	B = int(input_data[i].rstrip().split()[1])
	ptmp = input_data[i+1].rstrip().split()
	plist = []
	for p in ptmp:
		plist.append(float(p))
	i += 2
	#[<earliest error at first index> <earliest error at 2nd index> ... <earliest error at nth index> <whole string is correct>]
	#=[<1 - p1> <p1*(1 - p2)> <p1*p*(1 - p3)2> ... <p1*p2...*p{n-1}*(1 - pn)> <p1*p2*...*pn>]
	prob = [] #probability of earliest error occuring at that index
	for pi in range(len(plist)):
		ptmp = 1 - plist[pi]
		for pj in range(pi):
			ptmp *= plist[pj]
		prob.append(ptmp)
	ptmp = 1
	for pi in range(len(plist)):
		ptmp *= plist[pi]
	prob.append(ptmp)
	#print prob
	#print sum(prob)
	
	expected = []
	#keep typing
	#  all correct => remaining chars (B-A) + enter (1)
	#  any incorrect => remaining chars (B-A) + enter (1) + retyping password (B) + enter (1)
	expected.append((B-A+1)*prob[-1] + (2*B-A+2)*(1-prob[-1]))
	#backspace
	#  backspace c characters
	#  backspace before earliest error <= (A-c > index of prob)
	#  if backspace before earliest error => backspaces (c) + retyping (c + B-A) + enter (1)
	#  if not backspace before earliest error => all of above (2c+B-A+2) + retype password (B) + enter (1)
	for c in range(1,A+1):
		print '\t', sum(prob[A-c:]), sum(prob[:A-c])
		expected.append((2*c+B-A+1)*sum(prob[A-c:]) + (2*c+2*B-A+2)*sum(prob[:A-c]))
	#enter right away
	#  enter (1) + retyping (B) + enter (1)
	#  note that A<B so entering right away will never be correct in that entry
	expected.append(B+2)
	
	print prob
	print expected
	print
	
	output += 'Case #%d: %.6f\n'%(n+1,round(min(expected),6))

###########################################################
# output
###########################################################

outfile = open('output_small.txt','w')
#outfile = open('output_large.txt','w')
outfile.write(output)
outfile.close()