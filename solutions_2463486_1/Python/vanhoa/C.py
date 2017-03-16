import sys
def rev(n):
	r=0;
	while n>0:
		r=r*10+(n%10)
		n//=10
	return r

def f7(seq):
    seen = set()
    seen_add = seen.add
    return sorted([ x for x in seq if x not in seen and not seen_add(x)])	
def genList(maxDigit):
	curr_list=[[1,2,3]]
	res=[1,2,3,11,22,101,111,121,202,212]
	p10=10
	for len in xrange(3,maxDigit+1,2):
		p10=10*p10
		now_list=[]
		last_list = curr_list[-1]
		for last_pre in last_list:
			for suf in xrange(0,3):
				newpre=last_pre*10+suf
				n=newpre*p10+rev(newpre)
				if n*n==rev(n*n):
					now_list.append(newpre)
					res.append(n)
		for last_pre in last_list:
			for suf in xrange(0,3):
				for cen in xrange(0,3):
					newpre=last_pre*10+suf
					n=newpre*p10*10+cen*p10+rev(newpre)
					if n*n==rev(n*n):
						now_list.append(newpre)
						res.append(n)
		curr_list.append(f7(now_list))
	return res
	
nr={};
oldout=sys.stdout
sys.stdout=open("C.val","w")
r=genList(52);
for x in r:
	print str(x*x)
sys.stdout=oldout

for x in xrange(0,100):
	nr[x]=0
for x in r:
	nr[len(str(x))] += 1
for (x,y) in nr.iteritems():
	if y>0: print x,y