#!/usr/bin/env python
# -*- coding: utf-8

from sys import stdin
from math import floor

def readCase():
	return map(long, stdin.readline().split())

def parse():
	T = long(stdin.readline())
	cases = []
	for i in range(T):
		cases.append(readCase())
	return cases

def main():
	inp = parse()
	for i, case in enumerate(inp):
		print "Case #{0}: {1}".format(i+1,long(floor(.25*(floor((4*long(case[0]**2)-4*long(case[0])+8*case[1]+1)**.5)-long(2*case[0])+1))))

if __name__=="__main__":
	main()
