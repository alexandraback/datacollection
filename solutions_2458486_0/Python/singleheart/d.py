#!/usr/bin/python

# A. Lawnmower

import sys

types = []
chests = []

def find(keys, isOpened):
	if len(keys) <= 0 or isOpened.count(False) == 0:
		return []
	k = keys[:]
	t = []
	for i in range(len(isOpened)):
		if not isOpened[i]:
			t.append(types[i])
			for item in chests[i]:
				if item == types[i] and item not in keys:
					continue
				k.append(item)
	for item in t:
		if item in k:
			k.remove(item)
		else:
			return []

	for i in range(len(chests)):
		if isOpened[i] or (types[i] not in keys): 
			continue
		isOpened[i] = True
		keys.remove(types[i])
		keys += chests[i]
		result = find(keys, isOpened)
		if isOpened.count(False) == 0:
		 	result.insert(0, i+1)
			return result
		else:
			isOpened[i] = False
			for item in chests[i]:
				keys.remove(item)
			keys.append(types[i])

	return []


f = sys.stdin
T = int(f.readline())

for t in range(1, T+1):
	print "Case #%d:" % t,

	K, N = [int(i) for i in f.readline().strip().split()]
	keys = [int(i) for i in f.readline().strip().split()]
	types = []
	chests = []
	for n in range(N):
		l = [int(i) for i in f.readline().strip().split()]
		types.append(l[0])
		chests.append(l[2:])

	isOpened = [False for e in chests]
	result = find(keys, isOpened)

	if isOpened.count(False) > 0 or len(result) < N:
		print "IMPOSSIBLE"
	else:
		print str(result)[1:-1].replace(',','')
