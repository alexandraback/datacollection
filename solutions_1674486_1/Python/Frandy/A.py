#!/usr/bin/python

import sys

sys.setrecursionlimit(1000000)

inname = "input.txt"
outname = "output.txt"
if len(sys.argv)>1:
	inname = sys.argv[1]
	outname = inname.rstrip(".in")
	outname = outname + ".out"
fin = open(inname,"r")
fout = open(outname,"w")

def findPath(N,data,i,rec):
#	print "to visit line",i
	flag = 0		
	rec[i] += 1;
	if rec[i]>=2:
		flag = 1;
		return [flag,rec]	
	if data[i][0]==0:
		return [flag,rec]
	else:
		for v in data[i][1:]:
			[flag,rec] = findPath(N,data,v,rec)
			if flag==1:
				break
	return [flag,rec]
		

def solveN(N,data):
	res = "No"	
	for i in range(1,N+1):
		if data[i][0]>=2:		
	#		print "test line",i
			rec = [0 for j in range(N+1)]
			(flag,rec) = findPath(N,data,i,rec)
			if flag==1:
				res = "Yes"	
				break
	return res

line = fin.readline().rstrip("\n")
testCaseNum = int(line)
for caseNum in range(testCaseNum):
	N = int(fin.readline().rstrip("\n"))	
	data = [[0]]
	for i in range(N):	
		tmp = [int(v) for v in fin.readline().rstrip("\n").split()]	
		data.append(tmp)
	print "case ",(caseNum+1)
	res = solveN(N,data)
	answer = "Case #%d:" %(caseNum+1)
	answer += " " + res + "\n"
	fout.write(answer)

fin.close()
fout.close()
