#!/bin/python
#import time
#from decimal import *

#_modulo = 10**9 + 7


def main():
	
	import sys
	#import math
	#from Queue import PriorityQueue
	#from operator import itemgetter
	#from sets import Set
 
	_cache = {}
	
	T= int(sys.stdin.readline().strip())
	
	for _t in range(T):
		s = sys.stdin.readline().strip()
		
		if s not in _cache:
			_first = s[0]
			_last  = s[0]
			_group = {'+':0, '-':0}
			
			for k in s:
				if _last != k:
					_group[_last] += 1
				_last = k
			
			_group[_last] += 1
		
			if _group['-'] == 0:
				_cache[s] = '0'
			elif _group['+'] == 0:
				_cache[s] = '1'
			else:
				_cost1 = 2*_group['-'] 
				if _first == '-':
					_cost1 -= 1
				
				_cost2 = 1 + 2*_group['+'] 
				if _last == '+':
					_cost2 -=1
				_cache[s] = str(min(_cost1,_cost2))
		
		_res = "Case #"+str(_t+1)+": "+_cache[s]
		print _res
	
		
		
	
		
		
	
if __name__ == "__main__":
	
	#s= time.time()
	main()
	
	#print time.time()-s
	