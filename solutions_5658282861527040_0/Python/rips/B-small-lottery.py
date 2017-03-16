#! /usr/bin/env python
import math


#################################################################################################

def parseInputData(problem, s_input, s_id):
	finput = open(problem + '-' + s_input + '-' + s_id + '.in','r')
	nCase = int(finput.readline().strip())
	inputList = finput.readlines()	
	finput.close()
	return nCase, inputList

#################################################################################################

def writeOutput(result, problem, s_input, s_id):
	foutput = open(problem + '-' + s_input + '-' + s_id + '.out','w')
	foutput.writelines(result)
	foutput.close()
	
#################################################################################################

def StrToNumList(s):
	s = s.strip()
	return [int(x) for x in s.split()]

def StrToNum(s):
	return int(s.strip())

def StrToNum(s):
	return int(s.strip())

#################################################################################################



def solve_lottery(p):
	A, B, K = StrToNumList(p[0])
	res = 0

	for i in range(A):
		for j in range(B):
			if i & j < K:
				res += 1

	return str(res)



	

###################################################################################################
					
problem = 'B'
s_input = 'small'
s_id = 'lottery'

nCase, inputList = parseInputData(problem, s_input, s_id)
result = []
rownum = 0

for i in range(nCase):
	n = 0 #StrToNum(inputList[rownum])	
	result.append("Case #%d: %s\n" %(i+1, solve_lottery(inputList[rownum : rownum + n + 1])))
	rownum += n + 1
	
writeOutput(result, problem, s_input, s_id)



		




		

