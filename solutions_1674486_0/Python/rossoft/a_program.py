#!/usr/bin/python
import sys


def construct_vector(M):
	children = dict()
	for i in xrange(len(M)):
		Mi = M[i]
		for j in Mi:
			parent = int(j)
			if (not parent in children):
				children[parent] = []
			
			children[parent].append( i+1 )
	return children

def find_repeated(j,children):
	visited = {}

	queue = []
	for i in children[j]:
		queue.append(i)
	while len(queue) >0:
		item = queue.pop()
		if (item in visited):
			return True
		visited[item] = True

		if (item in children):		
			for child in children[item]:
				queue.append(child)
		
	return False

def find_subpaths(i,children):
	for j in children[i]:
		#print "find repeated",j,children
		if (find_repeated(j,children)):
			return True
			
	return False

def find_diamonds(M):
	
	children = construct_vector(M)
	for i in children:
		if (len(children[i]) > 1):
			#print "searching in",i,children[i]
			repeated = find_repeated(i,children)
			if (repeated):
				return True
	
	return False
	
def main():
	T = int(sys.stdin.readline())
	
	for t in xrange(T):
		N = int(sys.stdin.readline().strip())
		M = []
			
		for i in xrange(N):
			parts = sys.stdin.readline().split(" ")
			
			Mi = int(parts[0])
			if (len(parts)-1 != Mi):
				print "ERROR",len(parts)-1,Mi
				sys.exit(1)
	
			if (len(parts)>0):
				M.append(parts[1:])
			else:
				M.append([])
	
		#if (N != 5):
		#	continue
	#	print N,M

		diamonds = find_diamonds(M)
		if (diamonds):	
			print "Case #" + str(t+1) + ": Yes"
		else:
			print "Case #" + str(t+1) + ": No"
main()
