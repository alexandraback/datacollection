import math
import numpy as np
import sys
argument = (sys.argv) 
inputName = str(argument[1])
outputName = str(argument[2])
textfile = open(inputName);
lines = [line.strip() for line in textfile]
textfile.close()

textfile = open(outputName,"w");
numCases = int( lines[0])
l = 1
for i in range(0,numCases,1):
	charlist = list(lines[l].split())
	
	name = str(charlist[0])
	n_number = int(charlist[1])
	#print name 
	#print n_number
	n_value = 0
	#compute substrings with x ranging from 0 to string length and y ranging from x+1 to string length
	for x in range(0,len(name)+1,1):
		for y in range(x,len(name)+1,1):
			currstring = name[x:y]
			
			cnt = 0
			for v in range(0,y-x,1):
				if(currstring[v] != 'a' and currstring[v] != 'e' and currstring[v] != 'i' and currstring[v] != 'o' and currstring[v] != 'u'):
					cnt = cnt + 1
				else:
					if (cnt >= n_number):
						n_value = n_value + 1
						cnt = 0
						break
						
					cnt =  0
					
			if ( cnt >= n_number):
				n_value = n_value + 1
	
	#print n_value					
	textfile.write("Case #{case_no}: {ans}\n".format(case_no = i+1, ans = n_value))		
	
	l = l + 1






textfile.close()
