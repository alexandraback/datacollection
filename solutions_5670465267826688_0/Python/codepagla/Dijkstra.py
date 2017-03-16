res={('1','1'):'1',('1','i'):'i',('1','j'):'j',('1','k'):'k',\
     ('i','1'):'i',('i','i'):'-1',('i','j'):'k',('i','k'):'-j',\
     ('j','1'):'j',('j','i'):'-k',('j','j'):'-1',('j','k'):'i',\
     ('k','1'):'k',('k','i'):'j',('k','j'):'-i',('k','k'):'-1'}

t=int(input())
for i in xrange(1,t+1) :
	L,X=map(int,raw_input().split())
	s=raw_input()
	s=s*X
#	print s
	neg=0
	left='1'
	middle='1'
	right='1'
	left_found=False
	middle_found=False
	right_found=False
	for indx in xrange(L*X) :
		if not left_found :
			left=res[(left,s[indx])]
			if len(left)==2 :
				neg=1-neg
				left=left[-1]
			if left=='i' and neg==0:
				left_found=True
		elif not middle_found :
			middle=res[(middle,s[indx])]
			if len(middle)==2 :
				neg=1-neg
				middle=middle[-1]
			if middle=='j' and neg==0:
				middle_found=True
		else :
			right=res[(right,s[indx])]
			if len(right)==2 :
				neg=1-neg
				right=right[-1]
			if right=='k' and neg==0:
				right_found=True
			else :
				right_found=False
#		print "l=",left,"m=",middle,"r=",right

	if left_found and middle_found and right_found :
		print "Case #%d:"%(i),"YES"
	else :
		print "Case #%d:"%(i),"NO"
					
