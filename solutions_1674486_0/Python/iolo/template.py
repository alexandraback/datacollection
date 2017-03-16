#!/usr/bin/python

import sys
import copy

class gClass:
	nodes=[]
	name=0
	
	def __init__(self,_n):
		self.nodes = []
		self.name=_n
	def addNode(self,_n):
		self.nodes.append(_n)
	def show(self):
		print self.name
		print self.nodes
	def nParents(self):
		return len(self.nodes)

class camino:
	nodes=[]
	complete=0

	def __init__(self):
		self.nodes=[]
		complete=0
	def addNode(self,_n):
		self.nodes.append(_n)
	def show(self):
		print self.nodes
	def current(self):
		return self.nodes[-1]

classTree=[]
caminos=[]

def processCase():
	global classTree
	global caminos
	# *** BEGIN CODE PROCESSING CASE ***

	# create initial paths
	caminos=[]
	caminos2=[]
	for i in classTree:
		c = camino()
		c.addNode(i.name)
		caminos.append(c)

	# itera caminos
	remaining=1
	while remaining==1:
		remaining=0
		for c in caminos:
			if c.complete==0:
				remaining=1
				actual=classTree[c.current()-1]
				if actual.nParents()==0:
					c.complete=1
				elif actual.nParents()==1:
					c.addNode(actual.nodes[0])
				else:
					for nc in actual.nodes:
						if nc != actual.nodes[0]:
							x=copy.deepcopy(c)
							x.addNode(nc)
							caminos.append(x)
					c.addNode(actual.nodes[0])

	# fuera triviales
	for c in caminos:
		if len(c.nodes)	>1:
			caminos2.append(c)	

	for c1 in caminos2:
		for c2 in caminos2:
			if c1!=c2:
				if c1.nodes[0]==c2.nodes[0]:
					if c1.nodes[-1]==c2.nodes[-1]:
						return "Yes" 

	# *** END CODE PROCESSING CASE ***
	return "No"

def readCase(case):

	global classTree

	# *** BEGIN CODE READING CASE ***
	caseInput=sys.stdin.readline()

	classTree=[]
	for i in xrange(int(caseInput)):
		line=sys.stdin.readline()
		rel=line.split()
		rel.pop(0)
		n=gClass(i+1)
		for j in rel:
			n.addNode(int(j))
		classTree.append(n);
		
	#print "Clases: "
	#for n in classTree:
	#	n.show()

	# *** END CODE READING CASE ***

	solution=processCase()
	print "Case #"+str(case)+": "+solution

cases=int(sys.stdin.readline())

for case in range(cases):
	readCase(case+1)

