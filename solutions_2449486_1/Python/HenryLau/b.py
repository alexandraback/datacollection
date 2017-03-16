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
		para1 = readints(f)
		para2 = [readints(f) for i in range(para1[0])]
		result = solver(para1 ,para2)
		o.write("Case #"+str(x+1) + ": " + result + '\n')
		logging.debug(str(x+1)+ "/"+ str(no_cases) +"Done")
	f.close()
	o.close()



def solver(para1, para2):
	if any([any([j > 100 for j in i]) for i in para2]):
		return "NO"
	

	test = para2
	n = len(test)
	m = len(test[0])
	t = [[0 for i in xrange(m)] for j in xrange(n)]
	for i in xrange(n):
		for j in xrange(m):
			left = [k <= test[i][j] for k in test[i][:j]]
			right = [k <= test[i][j] for k in test[i][j+1:]]
			if all(left) and all(right):
				t[i][j] += 1

	test = zip(*para2)
	n = len(test)
	m = len(test[0])
	for i in xrange(n):
		for j in xrange(m):
			left = [k <= test[i][j] for k in test[i][:j]]
			right = [k <= test[i][j] for k in test[i][j+1:]]
			if all(left) and all(right):
				t[j][i] += 1


	if any([any([j == 0 for j in i]) for i in t]):
		return "NO"
	return "YES"
main()