numcases=int(raw_input())

def pprint(a,b):
	print
	for i in a:
		print i,
	print
	for j in b:
		print j,


for i in xrange(0,numcases):
	print "Case #%d:"%(i+1),

	#exactly 20 numbers
	nums=map(int,raw_input().split()[1:])
	#have the numbers

	#iterate over all subsets
	flag=False
	sums={}
	for i in xrange(1048576,2097152):
		setA=[]
		for k,v in enumerate(nums):
			if (1048576>>(k+1)) & i:
				setA.append(v)
		tsum=sum(setA)
		if tsum in sums:
			pprint(setA,sums[tsum])
			flag=True
			break
		else:
			sums[tsum]=setA
	if not flag:
		print "Impossible",
	print
