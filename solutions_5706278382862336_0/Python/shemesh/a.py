import random
import sys
import time
from fractions import gcd

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
			


			
def ispow2(num):
	found = 0
	while num>0:
		if num&1==1:
			if found==1:
				return False
			found=1
		num /= 2
	return True
			
#def countrem(p,q):
	
	
Output = []
T = get_params(int)
te = time_est(T,10)

for i in xrange(T):
	te.calc_time(i)
	if i % 10 == 0:
		debug('Started %d' % i)
		
	
	
	P,Q=[int(x) for x in raw_input().split('/')]
	common = gcd(P,Q)
	P = P/common
	Q = Q/common
	pdq = float(P)/Q
	
	res=True
	gen1=0
	gen2=0
	while pdq<1:
		gen1+=1
		pdq*=2
	left = 1/pdq
	if left+gen1>40:
		res=False
	if not ispow2(Q):
		res=False
	#R,N,M,K = get_params(int,int,int,int)

	if res:
		Output += ['Case #%d: %d' % (i+1,gen1)]
	else:
		Output += ['Case #%d: impossible' % (i+1)]

	

		
for l in Output:
	print l
