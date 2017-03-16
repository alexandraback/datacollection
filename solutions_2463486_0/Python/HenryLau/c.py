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
		logging.debug(para1)
		# para2 = readstr(f)
		# para3 = readstr(f)
		# para4 = readstr(f)
		result = solver(para1)
		o.write("Case #"+str(x+1) + ": " + result + '\n')
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

def solver(para):
	count = 0
	for i in xrange(1,int(math.sqrt(para[1]))+1):
		if isPalindrome(i):
			sq = i * i
			if sq >= para[0] and isPalindrome(sq):
				count += 1
	return str(count)

main()