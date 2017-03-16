#!/usr/bin/env python
from collections import deque

def process_file(file):
	fsock = open(file)
	text = fsock.read()
	fsock.close()
	lines = text.split('\n')
	return lines


def process_lines(lines):
	ans = []
	first = True
	case = {}
	F = []
	N = -1
	for line in lines:
		if first == True:
			first = False
		elif line == '':
			case['C'] = C
			case['F'] = F
			ans.append(case)
			return ans
		elif len(case) == 0 or len(F) == N:
			if len(case) > 0:
				case['C'] = C
				case['F'] = F
				ans.append(case)
			case = {}
			H = -1
			N = -1
			M = -1
			C = []
			F = []
			for num in line.split(' '):
				if H == -1:
					H = int(num)
				elif N == -1:
					N = int(num)
				elif M == -1:
					M = int(num)
			case['H'] = H
			case['N'] = N
			case['M'] = M
		elif len(C) < N:
			c = []
			for n in line.split(' '):
				c.append(int(n))
			C.append(c)
		else:
			f = []
			for n in line.split(' '):
				f.append(int(n))
			F.append(f)


def process_case(line):
	H = line['H']
	N = line['N']
	M = line['M']
	C = line['C']
	F = line['F']
	initialStarts = getInitialStarts(H, C, F, N, M)
	best = sys.maxint
	for start in initialStarts:
		startBest = getBest(start, H, C, F, N, M)
		if startBest != None and startBest < best:
			best = startBest
	return best

def getBest(start, H, C, F, N, M):
	tried = {}
	q = []
	q.append((0.0, start))
	while len(q) > 0:
		cur = q[0]
		q.remove(q[0])
		curTime = cur[0]
		curPos = cur[1]
		if tried.has_key(curPos) and tried[curPos] < curTime:
			continue
		tried[curPos] = curTime
		if curPos[0] == N - 1 and curPos[1] == M - 1:
			return curTime
		possibleMoves = getPosMoves(cur, tried, H, C, F, N, M)
		for pm in possibleMoves:
			if tried.has_key(pm[1]) and tried[pm[1]] < pm[0]:
				continue
			tried[pm[1]] = pm[0]
			if len(q) == 0:
				q.append(pm)
			else:
				for i in range(len(q)):
					if pm[0] < q[i][0]:
						q.insert(i, pm)
					elif i == len(q) - 1:
						q.append(pm)

def getPosMoves(cur, tried, H, C, F, N, M):
	curH = H - (cur[0] * 10.0)
	possible = []
	cell = cur[1]
	possible.append((cell[0], cell[1] + 1))
	possible.append((cell[0], cell[1] - 1))
	possible.append((cell[0] + 1, cell[1]))
	possible.append((cell[0] - 1, cell[1] + 1))
	result = []
	for p in possible:
		if p[0] < 0 or p[0] >= N or p[1] < 0 or p[1] >= M:
			continue
		if p not in tried:
			t = getTime(cur, p, H, C, F, N, M)
			if t > 0:
				result.append((t, p))
	return result

def getTime(cur, p, H, C, F, N, M):
	time = cur[0]
	ceilingCur = C[cur[1][0]][cur[1][1]]
	ceilingAdj = C[p[0]][p[1]]
	floorCur = F[cur[1][0]][cur[1][1]]
	floorAdj = F[p[0]][p[1]]
	if canMove([cur[1], p], 0, C, F):
		curH = H - (time * 10.0)
		if curH + 50 > ceilingAdj:
			targetH = ceilingAdj - 50
			time += (curH - targetH) / 10.0
			curH = targetH
		if curH - floorCur < 20:
			time += 10
		else:
			time += 1
		return time
	else:
		return -1

def getInitialStarts(H, C, F, N, M):
	initialStarts = set([(0, 0)])
	q = deque([])
	if N > 1:
		q.append([(0, 0), (1, 0)])
	if M > 1:
		q.append([(0, 0), (0, 1)])
	while len(q) > 0:
		t = q.popleft()
		if canMove(t, H, C, F):
			initialStarts.add(t[1])
			for m in getPossibleMoves(t[1], initialStarts, N, M):
				q.append(m)
	return initialStarts

def canMove(t, H, C, F):
	ceilingCur = C[t[0][0]][t[0][1]]
	ceilingAdj = C[t[1][0]][t[1][1]]
	floorCur = F[t[0][0]][t[0][1]]
	floorAdj = F[t[1][0]][t[1][1]]
	'''print '----'
	print H
	print ceilingCur
	print floorCur
	print ceilingAdj
	print floorAdj
	print '*****'
	'''
	if H + 50 <= ceilingAdj and floorCur + 50 <= ceilingAdj and floorAdj + 50 <= ceilingAdj:
		if floorAdj + 50 <= ceilingCur:
			return True
	return False

def getPossibleMoves(cell, initialStarts, N, M):
	possible = []
	p1 = (cell[0], cell[1] + 1)
	p2 = (cell[0], cell[1] - 1)
	p3 = (cell[0] + 1, cell[1])
	p4 = (cell[0] - 1, cell[1])
	if isPossible(p1, initialStarts, N, M):
		possible.append([cell, p1])
	if isPossible(p2, initialStarts, N, M):
		possible.append([cell, p2])
	if isPossible(p3, initialStarts, N, M):
		possible.append([cell, p3])
	if isPossible(p4, initialStarts, N, M):
		possible.append([cell, p4])
	return possible

def isPossible(p, initialStarts, N, M):
	if p in initialStarts:
		return False
	if p[0] < 0 or p[0] >= N:
		return False
	if p[1] < 0 or p[1] >= M:
		return False
	return True

if __name__ == "__main__":
	import sys
	filename = sys.argv[1]
	lines = process_file(filename)
	lines = process_lines(lines)
	c = 0
	for line in lines:
		c += 1
		print "Case #%d: %s" % (c, process_case(line))