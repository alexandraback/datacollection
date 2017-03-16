import re

fr = open("input.in", 'r')
fw = open("output.txt", 'w')

lines = fr.readlines()

numTests = lines[0].strip()
curTest = 0
curLine = 1

def getLine():
	global curLine
	global lines
	curLine += 1
	return lines[curLine-1]
	
def getMult():
	return getLine().strip().split()

def getMultInt():
	return map(int, getMult())
	
def getMultFloat():
	return map(float, getMult())

minA = 1000
minB = 1000
minDif = 1000
minAstr = ""
minBstr = ""
def terriblySlow(aVal, bVal, A, B, idx, aStr, bStr):
	global minA
	global minB
	global minDif
	global minAstr
	global minBstr
	
	if idx == len(A):
		if abs(aVal - bVal) < minDif:
			minA = aVal
			minB = bVal
			minAstr = aStr
			minBstr = bStr
			minDif = abs(aVal - bVal)
		elif abs(aVal - bVal) == minDif:
			if aVal < minA:
				minA = aVal
				minB = bVal
				minAstr = aStr
				minBstr = bStr
			elif aVal == minA and bVal < minB:
				minB = bVal
				minAstr = aStr
				minBstr = bStr
		return
		
	if A[idx] == "?" and B[idx] == "?":
		for a in range(10):
			for b in range(10):
				terriblySlow(aVal*10 + a, bVal*10 + b, A, B, idx+1, aStr+str(a), bStr+str(b))
				
	elif A[idx] == "?":
		b = int(B[idx])
		for a in range(10):
			terriblySlow(aVal*10 + a, bVal*10 + b, A, B, idx+1, aStr+str(a), bStr+B[idx])
			
	elif B[idx] == "?":
		a = int(A[idx])
		for b in range(10):
			terriblySlow(aVal*10 + a, bVal*10 + b, A, B, idx+1, aStr+A[idx], bStr+str(b))
			
	else:
		a = int(A[idx])
		b = int(B[idx])
		terriblySlow(aVal*10 + a, bVal*10 + b, A, B, idx+1, aStr+A[idx], bStr+B[idx])
		
	
while curTest < int(numTests):
	#A = int(getLine())
	#A = list(getMultInt())
	#A, B = getMultInt()
	#A = getMultFloat()
	A, B = getLine().strip().split()
	
	minA = 1000
	minB = 1000
	minDif = 1000
	minAstr = ""
	minBstr = ""
	terriblySlow(0, 0, A, B, 0, "", "")
	
	fw.write("Case #%d: %s %s\n" % (curTest+1, minAstr, minBstr))
	curTest += 1
					
fr.close()
fw.close()