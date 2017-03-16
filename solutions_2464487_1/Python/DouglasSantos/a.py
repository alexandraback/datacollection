#!/usr/bin/env python
# encoding: utf-8
"""
untitled.py

Created by Douglas Santos on 2013-04-26.
Copyright (c) 2013 __MyCompanyName__. All rights reserved.
"""

import sys
import os


def main():
	
	t = int(raw_input())
	for k in range(0, t):
		s = raw_input().split(" ")
		r = int(s[0])
		x = int(s[1])
		inicio = 0
		fim = x
		while True:
			if inicio > fim:
				break
			meio = (inicio + fim) / 2
			y = (meio*4+1 + 1) * (meio+1)
			y = y / 2
			y = y + (2*r*(meio+1))
			if y > x:
				fim = meio-1
			else:
				res = meio + 1
				inicio = meio + 1
		print "Case #%d: %d" % (k+1, res)

if __name__ == '__main__':
	main()

