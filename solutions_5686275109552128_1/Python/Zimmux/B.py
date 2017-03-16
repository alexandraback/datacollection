import fileinput
import math
stdin = fileinput.input()

def stackTime(ts,sMax):
	# time to make each stack <= sMax and then consume
	k = 0
	for i,t in enumerate(ts):
		if i>sMax:
			k += t*((i-1)/sMax)
	return k+sMax

def solveCase():
	d = int(stdin.next())
	p = list(map(int,stdin.next().split()))
	pMax = max(p)
	ts = [0]*(pMax+1)
	for pi in p:
		ts[pi] += 1
	# sLo = 1
	# vLo = stackTime(ts,1)
	# sHi = pMax
	# vHi = stackTime(ts,pMax)
	# while sLo+1<sHi:
	# 	sMid = (sLo+sHi)/2
	# 	v0 = stackTime(ts,sMid-1)
	# 	v1 = stackTime(ts,sMid)
	# 	if v0>v1:
	# 		sLo = sMid
	# 		vLo = v1
	# 	else:
	# 		sHi = sMid-1
	# 		vHi = v0
	# print ts
	# for i in range(1,pMax+1):
	# 	print i, stackTime(ts,i)
	# print 'lohi',vLo,vHi
	# return min(stackTime(ts,vLo),stackTime(ts,vHi))
	return min(stackTime(ts,i) for i in range(1,pMax+1))
	
for case in xrange(int(stdin.next())):
	print "Case #{0}: {1}".format(case+1,solveCase())