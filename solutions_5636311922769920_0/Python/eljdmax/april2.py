#!/bin/python
import time

#from decimal import *

#_modulo = 10**9 + 7

def metadrome(_min,_max,K):
	
	if _max == 0:
		return 1
		
	if _min == 0:
		_min = 1
	
	if _max > K-1:
		_max = K-1
	
	_res = 0
	_base = 1
	for i in range(_max, _min-1, -1) :
		_res += i*_base
		_base *= K
		
	return (_res+1) #for 1-indexed array
	
def main():
	
	import sys
	import math
	#from Queue import PriorityQueue
	#from operator import itemgetter
	#from sets import Set
 
	
	#  Using metadrome 

	T= int(sys.stdin.readline().strip())
	
	for _t in range(T):
		[K,C,S] = map(int, sys.stdin.readline().strip().split())
		
		
		if (C >= K):
			_res = str(metadrome(0,K-1,K))
		else:
			_top = int(math.ceil((K)/(C*1.0)))
			if (S < _top):
				_res = "IMPOSSIBLE"
			else:
				_pre = 0
				_res = ""
				for _step in range(C,(_top+1)*C,C):
					_res = _res + str(metadrome(_pre,_step-1,K)) + " "
					_pre = _step
				
		_out = "Case #"+str(_t+1)+": "+ _res
		
		print _out
	
		
		
		
		
	
if __name__ == "__main__":
	
	#s= time.time()
	main()
	
	#print time.time()-s
	