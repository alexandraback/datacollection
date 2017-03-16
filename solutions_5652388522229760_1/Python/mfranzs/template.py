def readFile(filename):
	global f
	global out
	f = open(filename+".in", 'r')
	out = open(filename+".out", 'w')

def readInt():
	global f
	return int(f.readline())