import os
import sys

os.chdir(sys.path[0])

if len(sys.argv) > 1 :
	inputfile = sys.argv[1]
	outputfile = inputfile+"_output.txt"
else :
	inputfile = "input.txt"
	outputfile = "output.txt"
	
inputf = open(inputfile,"r")
outputf = open(outputfile,"w")

lines = inputf.readlines()

print "Number of tests = {}".format(lines[0])
nr = int(lines[0])

def getnumber(str):
	list = [int(i) for i in str.split()]
	cnt = 0
	for i in range(0, list[0]):
		for j in range(0, list[1]):
			if ((i&j) < list[2]):
				cnt += 1
	return cnt

for test in range(1,1+nr):
	nr = getnumber(lines[test])
	#print nr
	print >>outputf,"Case #{}: {}".format(test,nr)

outputf.close()
