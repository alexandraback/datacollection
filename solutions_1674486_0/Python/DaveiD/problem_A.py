import sys
import re

def getreachables(inherits, idx):
	reachables = []
	
	for othernode in inherits[idx]:
		reachables.append(othernode)
		reachables.extend(getreachables(inherits, othernode))
	
	return reachables

def processProblem(nodelist):
	inherits = []
	
	for i in range(len(nodelist)):
		nodes = nodelist[i].split()
		nodes.pop(0)
		inherits.append([])
		for j in nodes:
			inherits[i].append(int(j)-1)
	
	diamond = 0
	for i in range(len(nodelist)):
		nodehash = {}
		for node in getreachables(inherits, i):
			if node in nodehash:
				diamond = 1
			else:
				nodehash[node] = 1
	
	if diamond:
		return "Yes"
	else:
		return "No"
	
def main():
	f_in = open(sys.argv[1], "rb")
	line = f_in.readline()

	# Getting total number of test cases
	total_tc_num = int(line.rstrip())
	count = 1

	# Processing input test cases
	if total_tc_num > 0:
		f_out = open(sys.argv[2], "w")
		while line and count <= total_tc_num:
			line = f_in.readline().rstrip()
			
			nodenum = int(line)
			nodelist = []
			cnum = 1
			
			while cnum <= nodenum:
				line = f_in.readline().rstrip()
				nodelist.append(line)	
				cnum += 1
				
			str = "Case #%d: %s" % (count, processProblem(nodelist))
			if count < total_tc_num:
				str += "\n"
			f_out.write(str)
			count += 1
		f_out.close()
	f_in.close()

if __name__ == '__main__' :
    main()