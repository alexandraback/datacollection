
import os
import sys

sys.setrecursionlimit(20000)

if len(sys.argv) > 1 :
	inputfile = sys.argv[1]
	outputfile = inputfile.split(".txt")[0]+"_output.txt"
else :
	inputfile = "input.txt"
	outputfile = "output.txt"

os.chdir(sys.path[0])

input = open(inputfile,"r")
lines = input.readlines()
input.close()

output = open(outputfile,"w")

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

def getMinimumTime(currentRate, farmCost, farmCookieRate, cookiesToWin) :
	finished = 0
	time = 0
	while not finished :
		currentTimeToWin = cookiesToWin / currentRate
		extraFarmTimeToWin = farmCost/currentRate + cookiesToWin/(currentRate+farmCookieRate)
		if (extraFarmTimeToWin<currentTimeToWin) :
			#add farm
			time += farmCost/currentRate
			currentRate += farmCookieRate
		else :
			time += cookiesToWin / currentRate	
			finished = 1

	return time

if len(lines) :
	nrOfTests = int(lines[0])
	lines = lines[1:]
	for test in range(nrOfTests) :
		line = lines[0]
		lines = lines[1:]
		params = retrieveParams(line)
		outputstr = "Case #"+str(test+1)+": "+str(getMinimumTime(2, params[0], params[1], params[2]))
		print outputstr
		output.write(outputstr+"\n")
	
output.close()

