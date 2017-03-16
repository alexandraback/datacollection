#!python
# -*- coding: utf-8 -*-

import sys

Num = int(sys.stdin.readline().strip())
Inf = 1000

for index in range(Num):
	Size = [int(y) for y in sys.stdin.readline().split()]
	map = [[[int(y), False] for y in sys.stdin.readline().split()] for x in range(Size[0])]

	while True:
		min_height = min([min([y[0] if y[1] == False else Inf for y in x]) for x in map])
		if min_height == Inf:
			print "Case #%d: YES" % (index + 1)
			break
		
		is_changed = False
		for i in range(Size[0]):
			for j in range(Size[1]):
				if map[i][j][0] != min_height and map[i][j][1] == False: break
			else:
				for j in range(Size[1]):
					if not map[i][j][1]:
						map[i][j][1] = True
						is_changed = True
		
		for j in range(Size[1]):
			for i in range(Size[0]):
				if map[i][j][0] != min_height and map[i][j][1] == False: break
			else:
				for i in range(Size[0]):
					if not map[i][j][1]:
						map[i][j][1] = True
						is_changed = True
		
		if not is_changed:
			print "Case #%d: NO" % (index + 1)
			break
