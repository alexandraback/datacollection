import os, sys

inFile = None
outFile = None

mapping = {}

def solveCase(caseNo):
	line = inFile.readline()
	translated = ""
	for x in line:
		if x.isalpha():
			translated += mapping[x]
		else:
			translated += x
	outFile.write("Case #{0}: {1}".format(caseNo, translated))

def main():
	t = int(inFile.readline().strip())
	for i in xrange(t):
		solveCase(i+1)

to   = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv"
fr   = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up"

def prepareMapping():
	mapping['y'] = 'a'
	mapping['e'] = 'o'
	mapping['q'] = 'z'
	mapping['z'] = 'q'

	for x in range(len(to)):
		mapping[to[x]] = fr[x]

	#print len(mapping)

if __name__ == '__main__':
	inFile = open('in.txt','rt')
	outFile = open('out.txt', 'wt')
	prepareMapping()
	main()