import os
import sys

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

def getScoresCheat(nblocks, kblocks):
	points = 0
	
	nblocks = sorted(nblocks)
	kblocks = sorted(kblocks)
	
	while len(nblocks) :
		#get rid of no win blocks and get his highest block
		if nblocks[0] < kblocks[0] :
			nblocks.pop(0)
			kblocks.pop(-1)
		
		#bluff with lowest if higher than his lowest
		elif nblocks[-1] > kblocks[0] :
			i = 0
			while (i < len(nblocks) ) and (nblocks[-i-1] > kblocks[0]):
				i += 1
			nblocks.pop(-i)
			kblocks.pop(0)
			points+= 1
		
		#shouldn't get here
		else :
			pass

	return points

def getScoresOptimal(nblocks, kblocks):
	points = 0
	
	nblocks = sorted(nblocks)
	kblocks = sorted(kblocks)

	while len(nblocks) :
		if (nblocks[-1] > kblocks[-1] ) :
			nblocks.pop(-1)
			kblocks.pop(0)
			points += 1
		elif (nblocks[-1] < kblocks[-1] ) :
			nblocks.pop(-1)
			kblocks.pop(-1)
		#shouldn't get here
		else :
			pass
	return points
	
def retrieveParams(lines):
	list = []
	nrofblocks = int(lines[0])
	nblocks = lines[1].split(" ")	
	nblocks = [ float(i) for i in nblocks ]
	kblocks = lines[2].split(" ")	
	kblocks = [ float(i) for i in kblocks ]
	return [nblocks, kblocks]

if len(lines) :
	nrOfTests = int(lines[0])
	lines = lines[1:]
	for test in range(nrOfTests) :
		game = lines[0:3]
		lines = lines[3:]
		params = retrieveParams(game)
		nblocks = params[0]
		kblocks = params[1]
		outputstr = "Case #"+str(test+1)+": "+str(getScoresCheat(nblocks, kblocks))+" "+str(getScoresOptimal(nblocks, kblocks))+"\n"
		print outputstr
		output.write(outputstr)
	
output.close()

