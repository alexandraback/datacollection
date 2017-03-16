import sys

mapping = {}

def createMapping(strings):
	for string in strings:
		for i in range(0, len(string[0])):
			mapping[string[0][i]] = string[1][i]
	mapping['q'] = 'z'
	mapping['z'] = 'q'

def decodeLine(line):
	result = ""
	for c in line:
		result += mapping[c]
	return result

if __name__=="__main__":
	t1 = ("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand")
	t2 = ("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities")
	t3 = ("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up")
	createMapping([t1,t2,t3])
	
	testcases = input()
	for i in range(1, testcases+1):
		line = raw_input()
		tline = decodeLine(line)
		print "Case #" + str(i) + ": " + tline
	
		
