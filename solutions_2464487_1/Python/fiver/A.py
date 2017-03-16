#!/usr/bin/python

import sys
import math	
import Queue
from datetime import datetime

startTime = datetime.now()
sys.setrecursionlimit(20000)

def readn(n):
	return [raw_input().strip() for i in range(n)]
def read():
	return raw_input().strip()
def readints():
	return map(int, read().split())
def readint():
	return readints()[0]
def wl(n, o):
	print("Case #{0}: {1}".format(n, o))
	
	
T = readint()
for TT in range(T):
    r, t = readints();

    root = (-2 * r + 1 + math.sqrt((2 * r - 1) * (2 * r - 1) + 8 * t)) / 4;
    x = int(math.floor(root))
    ans = x;
    for a in range(x+1, x-2, -1):
        if a > 0 and 2*a+(2*r-1) <= t/a: 
            ans = a
            break
    
    wl(1+TT, a);
	
	
	
	
#print(datetime.now()-startTime)