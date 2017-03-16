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
 
	_cache = {0:"INSOMNIA"}
	
	T= int(sys.stdin.readline().strip())
	
	for _t in range(T):
		i = int(sys.stdin.readline().strip())
		if not i in _cache:
			_track = {}
			s = i
			for k in str(s):
				_track[k]=1
			while len(_track) < 10:
				s += i
				for k in str(s):
					_track[k] =1
					
			_cache[i] = str(s)
		
		_res = "Case #"+str(_t+1)+": "+_cache[i]
		print _res
	
		
		
	
		
		
	
if __name__ == "__main__":
	
	#s= time.time()
	main()
	
	#print time.time()-s
	