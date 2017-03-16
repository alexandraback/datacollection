T = int(raw_input())
for case in range(1,T+1):
	line = [str(s) for s in raw_input()]
	start=-1
	start_p=''
	counter=0
	#print line
	for i in range(0,len(line)):
		current = line[i]
		if(i<len(line)-1):
			next = line[i+1]
			if(current!=next):
				for j in range(0,i+1):
					line[j] = next
				counter+=1 #flip
		elif(i==len(line)-1):
			if(current=='-'):
				for j in range(0,i+1):
					line[j] = '+'
				counter+=1 #flip
	#print line
	#print counter
	print 'Case #{}: {}'.format(case,counter)
	
		

