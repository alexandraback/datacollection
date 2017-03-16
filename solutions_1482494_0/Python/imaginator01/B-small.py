# -*- coding: utf-8 -*-

import sys
import os.path
import os, time, itertools
import multiprocessing as mulp

class Sample:
	def solve(self,level_num,ais,bis):
		#print"\nn:%d,s:%d,p:%d,params:%s"%(n,s,p,params)

		self.ais=ais
		self.bis=bis
		

		if level_num==0:
			return 0
		elif level_num==1:
			if self.ais[0]>0 and bis[0]>0:
				return "Too Bad"
			elif bis[0]==0:
				return 1
			elif self.ais[0]==0:
				if bis[0]>1:
					return "Too Bad"
				else:
					return 2


		self.fc = [0 for j in range(level_num)]
		
		self.ans=0
		self.rest = []
		for j in range(level_num):
			self.rest.append(j)

		self.money=0		
		for j in range(level_num):
			if bis[j] == 0:
				if j in self.rest:
					self.money+=2
					self.rest.remove(j)
					self.ans+=1
					#print j
					
		if len(self.rest)==0:
			return self.ans

		for j in range(level_num):	
			ret=self.second_scan(level_num)	
			if ret==-1:
				return self.ans
		
		for i in range(100):	
			for j in range(level_num):	
				if self.ais[j] <= self.money and j in self.rest and self.bis[j] > self.money:
					self.money+=1
					self.ans+=1
					self.fc[j]=1
					break
	
			ret=self.second_scan(level_num)	
			if ret==-1:
				return self.ans

		if len(self.rest)==0:
			return self.ans
		else:
			return "Too Bad"


	def second_scan(self,level_num):
		for i in range(100):	
			for j in range(level_num):	
				if self.bis[j] <= self.money:

					if j in self.rest:
						self.money+=2-self.fc[j]
						self.rest.remove(j)
						self.ans+=1
						break
			if len(self.rest)==0:
				return -1
		return 0	
	

def read_nums():
	return map(int, in_fh.readline().split())
def read_str():
	return in_fh.readline().rstrip('\r\n')

def read_testcase():
	level_num=int(in_fh.readline())
	ais = []
	bis = []	
	for i in range(level_num):
		a,b=read_nums()
		ais.append(a)
		bis.append(b)
	return {'level_num':level_num,'ais':ais,'bis':bis}

def read_testcases(test_num):
	for i in range(test_num):
		yield read_testcase()

def wrapper_of_solve(q):
	sample=Sample()
	return sample.solve(**q)

if __name__ == '__main__':

	input_name = sys.argv[1]
	root, ext = os.path.splitext(input_name)
	in_fh=open(input_name)

	test_num=int(in_fh.readline())

	output_name = root + ".out"
	out_fhs=[open(output_name,'w')]

	testcases = read_testcases(test_num)

	pool = mulp.Pool()
	#mul_iter = pool.imap(wrapper_of_solve, testcases)
	mul_iter = itertools.imap(wrapper_of_solve, testcases)

	for (i, r) in enumerate(mul_iter, start=1):
	    for f in out_fhs:
	        print >> f, "Case #%d: %s" % (i, str(r))
