#!/usr/bin/python
import sys
from collections import deque

sys.setrecursionlimit(200000000)

def numboxes(A,B):
	total_toys = 0
	A = deque(A)
	B = deque(B)
	if (len(A) > 0 and len(B)>0):
		(boxtype, boxnum) = A.popleft()
		(toytype, toynum) = B.popleft()
	
		max_toys = min(boxnum, toynum)
		if (boxtype == toytype):
			#I can create upto min (boxnum, toynum)
			total_toys += max_toys
			boxnum -= max_toys
			toynum -= max_toys
			
			if (boxnum >0):
				A.appendleft( (boxtype, boxnum) )
			if (toynum >0):
				B.appendleft( (toytype, toynum) )
				
			total_toys += numboxes(deque(A),deque(B))
		else:			
			#throw boxes
			new_A = deque(A)
			new_B = deque(B)
			new_B.appendleft( (toytype, toynum) )
			
			without_boxes = numboxes(new_A, new_B)

			#throw toys			
			new_A = deque(A)
			new_B = deque(B)
			new_A.appendleft( (boxtype, boxnum) )
			
			without_toys = numboxes(new_A, new_B)
			
			total_toys += max(without_boxes, without_toys)
				
	return total_toys

def main():
	T = int(sys.stdin.readline())
	
	for t in xrange(T):
		parts = sys.stdin.readline().split(" ")
		N = int(parts[0])
		M = int(parts[1])
			
		parts = sys.stdin.readline().split(" ")
		A = []
		for i in xrange(N):
			ai = int(parts[2*i].strip())
			Ai = int(parts[2*i+1].strip())
			
			A.append( (Ai,ai) )
		parts = sys.stdin.readline().split(" ")
		B = []
		for i in xrange(M):
			bi = int(parts[2*i].strip())
			Bi = int(parts[2*i+1].strip())
			B.append( (Bi, bi))
	
		num = numboxes(A,B)
	
		print "Case #" + str(t+1) + ": " + str(num)
main()
