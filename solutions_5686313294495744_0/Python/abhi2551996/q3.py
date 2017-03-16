for i in range(input()):
	print "Case #"+str(i+1)+":",
	n=input()
	a=[]
	for _ in range(n):
		a.append(raw_input().split())

	#print a
	count=0

	first=[]
	second=[]
	for j in range(n):
		first.append(a[j][0])
		second.append(a[j][1])
	#print first
	#print second

	j=0
	while len(first) and j<len(first):
	#	print "j: ",j
	#	print "irst[j]: ",first[j]
	#	print "first.count(first[j]): ",first.count(first[j])
		if first.count(first[j])>1:
	#		print "second[j]: ",second[j]
	#		print "second.count(second[j]): ",second.count(second[j])
			if second.count(second[j])>1:
				count+=1
				second.remove(second[j])
				first.remove(first[j])
		j+=1
	#	print "first: ",first
	#	print "second: ",second

	print count
