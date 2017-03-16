import logging
logging.basicConfig(level=logging.DEBUG, format='%(asctime)s - %(levelname)s - %(message)s')
import itertools
from pprint import pprint
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
		para2 = readints(f)
		para3 = [readints(f) for i in range(para1[1])]

		result = solver(para1 ,para2 ,para3)

		o.write("Case #"+str(x+1) + ": " + result + '\n')
		logging.debug(str(x+1)+ "/"+ str(no_cases) +"Done")
	f.close()
	o.close()

def openChest(chestsDic,keys,opened,total,keyDic):
	if len(opened) == total:
		return opened
	if not keys:
		return [];
	result = []
	dic = {}
	for x,y in keyDic.items():
		dic[x] = [j for j in y if j not in opened]
	for i in xrange(total):
		need = chestsDic[i][0]
		if i+1 not in opened and need in keys:
			if keys.count(need) == 1 and chestsDic[i][1] == 0 and len(dic[need]) != 1:
				continue
			nextkey = [j for j in keys] + chestsDic[i][2:]
			nextkey.remove(need)
			nextopened = [j for j in opened] + [i+1]
			result = openChest(chestsDic,nextkey,nextopened,total,dic)
			if result:
				return result
	return []


def solver(para1, para2, para3):
	ak = [i for i in para2]
	for i in para3:
		ak += i[2:]
	for i in para3:
		if i[0] not in ak:
			return "IMPOSSIBLE"
		ak.remove(i[0])
	keyDic = {}
	for i in range(para1[1]):
		keyDic[para3[i][0]] = keyDic.get(para3[i][0],[]) + [i+1]
	result = openChest(para3,para2,[],para1[1],keyDic)

	if result:
		return " ".join(map(str,result))
	return "IMPOSSIBLE"

main()