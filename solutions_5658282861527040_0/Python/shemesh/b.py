import random
import sys
import time

def debug(s):
	sys.stderr.write(str(s) + '\n')

def get_params(*types):
	line = (raw_input()).split()
	params = []
	for i in range(len(types)):
		params += [types[i](line[i])]
		
	if len(params)==1:
		return params[0]
		
	return tuple(params)
	
def bin_search(s,e,v,cmpfunc):
	if e-s<=1:
		return s
	m = (s+e)/2

	if cmpfunc(m,v):
		return bin_search(s,m,v,cmpfunc)
	else:
		return bin_search(m,e,v,cmpfunc)
	
class time_est:
	def __init__(self,totnum,iternum):
		self.totnum = totnum
		self.iternum = iternum
		self.start_time = time.time()
		
	def calc_time(self,iter):
		if iter == self.iternum:
			till_now = time.time() - self.start_time
			till_end = till_now * (self.totnum - iter) / (iter)
			debug('Estimated time to finish = %f seconds' % (till_end))
			


Output = []
T = get_params(int)
te = time_est(T,10)

for t in xrange(T):
	te.calc_time(t)
	if t % 10 == 0:
		debug('Started %d' % t)

	
	A,B,K = get_params(int,int,int)
	count = 0
	for a in range(A):
		for b in range(B):
			if a&b<K:
				count += 1
		
	Output += ['Case #%d: %d' % (t+1,count)]
	

		
for l in Output:
	print l
