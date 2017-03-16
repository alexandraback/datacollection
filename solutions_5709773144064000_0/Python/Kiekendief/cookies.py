
import os
import sys

sys.setrecursionlimit(10000)

os.chdir(sys.path[0])

input = open("input.txt","r")
lines = input.readlines()
input.close()

output = open("output.txt","w")

def retrieveParams(line):
	params = line.split(" ")
	params = [ float(i) for i in params ]
	return params

def getMinimumTime(currentRate, farmCost, farmCookieRate, cookiesToWin) :
	currentTimeToWin = cookiesToWin / currentRate
	extraFarmTimeToWin = farmCost/currentRate + cookiesToWin/(currentRate+farmCookieRate)
	if (extraFarmTimeToWin<currentTimeToWin) :
		#add farm
		return farmCost/currentRate + getMinimumTime(currentRate+farmCookieRate, farmCost, farmCookieRate, cookiesToWin)
	else :
		return cookiesToWin / currentRate	
	
if len(lines) :
	nrOfTests = int(lines[0])
	lines = lines[1:]
	for test in range(nrOfTests) :
		line = lines[0]
		lines = lines[1:]
		params = retrieveParams(line)
		print"Case #"+str(test+1)+": "+str(getMinimumTime(2, params[0], params[1], params[2]))
		

