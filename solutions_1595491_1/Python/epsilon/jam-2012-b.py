cases=int(input())

pntr=0

while pntr<cases:
	pntr+=1
	cntr=0
	marks=list(reversed(list(map(int,input().split()))))
	num=marks.pop()
	surp=marks.pop()
	maxi=marks.pop()
	for n in marks:
		q=n//3
		r=n%3
		if q>=maxi:
			cntr+=1
		if r==0:
			if surp>0:
				if q>0 and q+1==maxi:
					cntr+=1
					surp-=1
		if r==1:
			if q+1==maxi:
				cntr+=1
		if r==2:
			if q+1==maxi:
				cntr+=1
			if q+2==maxi and surp>0:
				cntr+=1
				surp-=1
	print('Case #'+str(pntr)+':',str(cntr))
