from collections import OrderedDict
from math import factorial

f = open('B-small-attempt0.in', 'rb')
g = open('output2', 'wb')

T = int(f.next())

dic =['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']



def solve(n, carr):
	ret = 1
	fact = 1
	carr = [ "".join(OrderedDict.fromkeys(car)) for car in carr]
	print carr
	midFlag = [0 for i in xrange(26)]
	flagStart= [0 for i in xrange(26)]
	flagEnd = [0 for i in xrange(26)]
	countTotal = [0 for i in xrange(26)]
	countStart = [0 for i in xrange(26)]
	countEnd = [0 for i in xrange(26)]
	for car in carr:
		for i, d in enumerate(dic):
			if car.count(d) == 1:
				countTotal[i] += 1
				if car.startswith(d):
					countStart[i] += 1
				if car.endswith(d):
					countEnd[i] += 1
				if not car.startswith(d) and not car.endswith(d) and midFlag[i]:
					return "0"
				elif not car.startswith(d) and not car.endswith(d):
					midFlag[i] = 1
			elif car.count(d) > 1:
				return "0"
	for i in xrange(26):
		if countTotal[i] == 1 or countTotal[i] == 0:
			continue
		if countStart[i] == countEnd[i]:
			ret = ret*countStart[i]
			fact += countStart[i] - 1
	return str(ret * factorial(fact))
		


for case in xrange(T):
	N = f.next()
	arr = f.next()
	arr = arr.split()
	g.write("Case #" + str(case+1) + ': ' + solve(N, arr) + '\n')
