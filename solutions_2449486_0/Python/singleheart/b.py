#!/usr/bin/python

# A. Lawnmower

import sys

def findMin(visited):
	for n in range(N):
		for m in range(M):
			if not visited[n][m]:
				return n, m
	return -1, -1


def isPossible(lawn, N, M):
	visited = [[False for i in range(M)] for i in range(N)]
	for n in range(N):
		for m in range(M):
			if lawn[n][m] > 1:
				visited[n][m] = True

	x, y = findMin(visited)
	while x >= 0 and y >= 0:
		canMowColumn = True
		for n in range(N):
			if lawn[n][y] > lawn[x][y]:
				canMowColumn = False
				break
		if canMowColumn:
			for n in range(N):
				visited[n][y] = True

		canMowRow = True
		for m in range(M):
			if lawn[x][m] > lawn[x][y]:
				canMowRow = False
				break
		if canMowRow:
			for m in range(M):
				visited[x][m] = True

		if (not canMowRow) and (not canMowColumn):
			return False

		x, y = findMin(visited)

	return True


f = sys.stdin
T = int(f.readline())

for t in range(1, T+1):
	print "Case #%d:" % t,

	N, M = [int(i) for i in f.readline().strip().split()]

	lawn = []
	for n in range(N):
		lawn.append([int(i) for i in f.readline().strip().split()])

	if isPossible(lawn, N, M):
		print "YES"
	else:
		print "NO"
