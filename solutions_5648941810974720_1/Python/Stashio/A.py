import re

def countBits(n):
	total = 0
	b = n
	while b > 0:
		total += 1
		b &= (b-1)
		
	return total

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

	
while curTest < int(numTests):
	S = getLine().strip()
	m = dict()
	digs = []
	total = 0
	for c in S:
		if c in m:
			m[c] += 1
		else:
			m[c] = 1
			#02368 579
			
	if "Z" in m:
		for i in range(m["Z"]):
			digs.append(0)
			m["Z"] -= 1
			m["E"] -= 1
			m["R"] -= 1
			m["O"] -= 1
		
	if "W" in m:
		for i in range(m["W"]):
			digs.append(2)
			m["T"] -= 1
			m["W"] -= 1
			m["O"] -= 1
		
	if "U" in m:
		for i in range(m["U"]):
			digs.append(4)
			m["F"] -= 1
			m["O"] -= 1
			m["U"] -= 1
			m["R"] -= 1
		
	if "X" in m:
		for i in range(m["X"]):
			digs.append(6)
			m["S"] -= 1
			m["I"] -= 1
			m["X"] -= 1
		
	if "G" in m:
		for i in range(m["G"]):
			digs.append(8)
			m["E"] -= 1
			m["I"] -= 1
			m["G"] -= 1
			m["H"] -= 1
			m["T"] -= 1
		
	if "H" in m:
		for i in range(m["H"]):
			digs.append(3)
			m["T"] -= 1
			m["H"] -= 1
			m["R"] -= 1
			m["E"] -= 1
			m["E"] -= 1
		
	if "O" in m:
		for i in range(m["O"]):
			digs.append(1)
			m["O"] -= 1
			m["N"] -= 1
			m["E"] -= 1
		
	if "S" in m:
		for i in range(m["S"]):
			digs.append(7)
			m["S"] -= 1
			m["E"] -= 1
			m["V"] -= 1
			m["E"] -= 1
			m["N"] -= 1
		
	if "V" in m:
		for i in range(m["V"]):
			digs.append(5)
			m["F"] -= 1
			m["I"] -= 1
			m["V"] -= 1
			m["E"] -= 1
		
	if "I" in m:
		for i in range(m["I"]):
			digs.append(9)
			m["N"] -= 1
			m["I"] -= 1
			m["N"] -= 1
			m["E"] -= 1
	
	fw.write("Case #%d: %s\n" % (curTest+1, "".join([str(c) for c in sorted(digs)])))
	curTest += 1
					
fr.close()
fw.close()