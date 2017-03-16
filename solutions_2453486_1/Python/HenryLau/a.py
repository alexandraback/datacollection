import logging
logging.basicConfig(level=logging.DEBUG, format='%(asctime)s - %(levelname)s - %(message)s')
import itertools
import math
from random import random

def readstr(f): return f.readline()[:-1]
def readfloat(f): return float(readstr(f))
def readint(f): return int(readstr(f))
def readstrs(f): return readstr(f).split(' ')
def readints(f): return map(int, readstrs(f))
def readfloats(f): return map(float, readstrs(f))

def main():
	fn = raw_input('File name: ')
	f = open(fn)
	o = open('output.txt','w')
	no_cases = readint(f)
	for x in xrange(no_cases):
		para1 = readstr(f)
		para2 = readstr(f)
		para3 = readstr(f)
		para4 = readstr(f)
		readstr(f)
		result = solver([para1 ,para2 ,para3,para4])
		o.write("Case #"+str(x+1) + ": " + result + '\n')
		logging.debug(str(x+1)+ "/"+ str(no_cases) +"Done")
	f.close()
	o.close()



def solver(para):
	empty = 0;
	tests = [para , zip(*para)]
	dia1 = []
	dia2 = []
	for i in range(4):
		dia1.append(para[i][i])
		dia2.append(para[i][3-i])
	tests.append([dia1,dia2])
	logging.debug(tests)
	for row in para:
		empty += row.count('.')
	for item in tests:
		for row in item:
			if (row.count('T') + row.count('X')) >= 4:
				return "X won"
			elif (row.count('T') + row.count('O')) >= 4:
				return "O won"
	if empty == 0:
		return "Draw"
	else:
		return "Game has not completed"


main()