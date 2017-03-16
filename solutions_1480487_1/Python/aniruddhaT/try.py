t = input()
for j in range(t):
	inp=raw_input().split()
	n = int(inp[0])
	n1 = float(inp[0])
	sum = 0.0
	list = []
	for i in range(n):
		list = list + [float(inp[i+1])]
		sum = sum+list[i]
	perc2 = 2.0
	count=0
	print "Case #"+str(j+1)+":",
	for i in range(n):
		if 2.0/n1 <=list[i]/sum:
			perc2 = perc2 - list[i]/sum
			count+=1
	for i in range(n):
		#print "list[i]=",list[i]
		if 2.0/n1 <=list[i]/sum:
			print "0.0",
		else:
			print 100.0*((perc2/(n1-count)) - (list[i]/sum)),
	print "\n",
