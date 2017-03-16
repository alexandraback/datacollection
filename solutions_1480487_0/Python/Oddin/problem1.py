#!/usr/bin/python

import sys
	
if 1==1:#sys.stdin.readline().rstrip("\n")=='Input':
	count = int(sys.stdin.readline(),10)
	for i in range(0,count):
#		print "1"
		line=sys.stdin.readline().rstrip("\n")
		
		s= line.split()
		num=int(s[0])
		jpoint = []
		for j in range(1,len(s)):
			jpoint.append(int(s[j],10))		
		X= sum(jpoint)
#		print count,jpoint
		result = []
		len_=len(jpoint)-1

		max_2=0.
		for x in range(len(jpoint)):
			p = 0.
			for y in range(len(jpoint)):
				if x!=y:
					p+=jpoint[y]
			r=100.*(p+X-len_*jpoint[x])/((len_+1)*X)
			
			
			
			result.append(r)
			
#			if r%1>0 or r==0 or r==100:
#				result.append(' '+"%.6f" % r)
#			else:
#				result.append(' '+"%.1f" % r)
			

		max_=0
		mc=0
		for e in range(len(result)):
				if result[e]<0:
					mc=mc+1
					max_=max_+result[e]
					result[e]=0.
		ku = len(result)-mc
#		print len(result)-mc,max_
		if mc>0:
			for e in range(len(result)):
				if result[e]>0:
					result[e]=result[e]+max_/ku*1.
			
		max_2 = 0.
		for w in result:
			max_2+=w
#		print max_2,'Result'
				
		line_out = ''
		for k in result:
			line_out=line_out+' '+"%.6f" % k
		sys.stdout.write("Case #"+str(i+1)+":"+line_out+"\n")
#		20+X*(1-xi)=10+X*(xi)
#		(20+X-10)/2X=*xi

#		3*20+3*X*xi+xi=p+X
# *len*20+len*X*xi+xi=(p+X-len*x)/(len*X+1)
#			10+30-20/(2)
#		xi(3*X+1)=(p+X-3*20)/(3*X+1)
#
	
#End
