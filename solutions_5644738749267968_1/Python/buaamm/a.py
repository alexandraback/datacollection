# -*- coding: utf-8 -*-
# Google Code Jam
# Create Date: 2014-04-10
# Created by: buaamm
#--------------------------------------------------------------------
import sys
import os

def nextint():
	return (int)(fr.readline())

def next():
	return fr.readline()

def write(s):
	fw.write(s)
	
def writeline(s):
	fw.write(s + "\n")

#--------------------------------------------------------------------
def solve():
	n = nextint()
	la = map(float, next().strip().split())
	lb = map(float, next().strip().split())
	
	la.sort()
	lb.sort()
	# Deceitful Case
	bleft = 0
	bright = n-1
	ans1 = 0
	for index in range(n):
		a = la[index]
		b = lb[bleft]
		if a > b:
			ans1 += 1
			bleft += 1
		else:
			bright -= 1
			
	# Normal Case
	la.reverse()
	lb.reverse()
	ans2 = 0
	bleft = 0
	bright = n-1
	for index in range(n):
		a = la[index]
		b = lb[bleft]
		if a > b:
			ans2 += 1
			bright -= 1
		else:
			bleft += 1
	
	
	write("%d %d\n" % (ans1,ans2) )
	
#--------------------------------------------------------------------
if __name__ == "__main__": ##__name__: [filename].py
	print "Hello, Main."
else:
	global fr, fw
	#fr = open('mm.in', 'r')
	#fw = open('mm.out', 'w')
	#prob_name = "A-small-practice"
	prob_name = "D-large"

	fr = open(prob_name + '.in', 'r')
	fw = open(prob_name + '.out', 'w')
	cas = (int)(fr.readline())
	for cs in range(cas):
		fw.write("Case #%d: " % (cs+1) )
		solve()
	fr.close()
	fw.close()
#--------------------------------------------------------------------


