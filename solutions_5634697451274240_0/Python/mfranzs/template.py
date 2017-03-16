def readFile(filename):
	global f
	global out
	f = open(filename+".in", 'r')
	out = open(filename+".out", 'w')

def readInt():
	global f
	return int(f.readline())

def readLn():
	global f
	return f.readline().replace("\n", "")

def answerLn(o):
	answer(str(o)+"\n")

def answer(o):
	print o,
	out.write(str(o))