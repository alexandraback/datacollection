curReadingLine = []

def readFile(filename):
	global f
	global out
	f = open(filename+".in", 'r')
	out = open(filename+".out", 'w')

def readInt():
	global curReadingLine
	if len(curReadingLine) ==0:
		curReadingLine = readLn().split(" ")
	r = curReadingLine[0]
	curReadingLine=curReadingLine[1:]
	return int(r)

def readLn():
	global f
	return f.readline().replace("\n", "")

def answerLn(o):
	answer(str(o)+"\n")

def answer(o):
	print o,
	out.write(str(o))