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
	allStuff = []
	allCases = []
	for x in xrange(no_cases):
		para1 = readints(f)
		# para2 = readstr(f)
		# para3 = readstr(f)
		# para4 = readstr(f)
		allCases.append(para1)
		allStuff += para1
	allStuff = list(set(allStuff))
	allStuff.sort()
	asf = allSquareAndFair(allStuff[0],allStuff[-1])
	
	logging.debug(asf)
	
	for x in xrange(no_cases):
		(l,h) = allCases[x]
		lc = getCount(asf,l)
		hc = getCount(asf,h)
		result = hc[0] - lc[0] + (1 if lc[1] else 0)
		o.write("Case #"+str(x+1) + ": " + str(result) + '\n')
		logging.debug(str(x+1)+ "/"+ str(no_cases) +"Done")
	f.close()
	o.close()

pDic = {};
def isPalindrome(i):
	result = pDic.get(i,None)
	if result is None:
		s = str(i)
		result = (s == s[::-1])
		pDic[i] = result
	return result

def getCount(l, n):
	if n > l[-1]:
		return (len(l) , False)
	for i in xrange(len(l)):
		if n == l[i]:
			return (i+1,True)
		elif l[i] > n:
			return (i, False)
	

def allSquareAndFair(f,t):
	logging.debug("Calculating all Square and Fair from " + str(f) + " to " + str(t))
	return [i*i for i in xrange(int(math.sqrt(f)),int(math.sqrt(t))+1) if isPalindrome(i) and isPalindrome(i*i)]
main()