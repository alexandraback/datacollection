# -*- coding: utf-8 -*-

import sys
import os.path
import os, time, itertools
import multiprocessing as mulp

class Sample:
	def solve(self,params,a,b,probs):
		#print"\nn:%d,s:%d,p:%d,params:%s"%(n,s,p,params)
		ans=0

		cands=[]
		
		cands.append(b+2)

		prod_a = 1
		for prob in probs:
			prod_a *= prob
		cands.append(b-a+1+(b+1)*(1-prod_a))
		
		for j in range(1,a+1):
			prod_j = 1
			for k in range(0,a-j):
				prod_j *= probs[k]			
			cand = 2*j+b-a+1+(b+1)*(1-prod_j)
			cands.append(cand)		
		
		best = cands[0]
		
		for cand in cands:
			if cand < best:
				best = cand
		
		return best

def read_nums():
	return map(int, in_fh.readline().split())
def read_str():
	return in_fh.readline().rstrip('\r\n')

def read_testcase():
	params = read_nums()
	a=params.pop(0)
	b=params.pop(0)
	probs = map(float, in_fh.readline().split())
	return locals()

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
	mul_iter = pool.imap(wrapper_of_solve, testcases)
	#mul_iter = imap(wrapper_of_solve, testcases)

	for (i, r) in enumerate(mul_iter, start=1):
	    for f in out_fhs:
	        print >> f, "Case #%d: %s" % (i, str(r))
