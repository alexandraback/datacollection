def func(line1,line2):
	box = []
	toy = []
	i=0
	while i<len(line1):
		box.append([line1[i],line1[i+1]])
		i=i+2
	i=0
	while i<len(line2):
		toy.append([line2[i],line2[i+1]])
		i=i+2
	print box
	print toy
	finals = []
	for ele in box:
		if not ele[1] in finals:
			finals.append(ele[1])
	i=0
	j=0
	count = 0
	prev = []
	while j!=len(toy) and i!=len(box):
		print box[i],toy[j]
		if [i,j]==prev:
			print "prev fail"
			if i+1!=len(box):
				i=i+1
			else:
				j=j+1
			continue
		if box[i][1] == toy[j][1]:
			ans = min(box[i][0],toy[j][0])
			count = count+ ans
			if(box[i][0] == ans):
				i=i+1
				toy[j][0]-=ans
				continue
			else:
				j=j+1
				box[i][0]-=ans
				continue
		if j+1==len(toy) and i+1==len(box):
			break
		if j+1!=len(toy) and i+1!=len(box) and box[i][1] == toy[j+1][1] and box[i+1][1] == toy[j][1]:
			c =  min(box[i][0],toy[j+1][0])
			d =  min(box[i+1][0],toy[j][0])
			if c>d:
				j=j+1
			else:
				i=i+1
			continue
		if j+1!=len(toy):
			if box[i][1] == toy[j+1][1]:
				j=j+1
				continue
		if i+1!=len(box):
			if box[i+1][1] == toy[j][1]:
				i=i+1
				continue
		prev =  [i,j]
		k=j
		print "here"
		while k<len(toy):
			if toy[k][1] in finals:
				break;
			k=k+1
		j=k
	print count
	return count


file = open("inputc1.txt")
t = file.readline()
out = open("outputc2xy.txt","w")
for i in range(0,int(t)):
	x = file.readline()
	print "testcase " ,i+1
	line1= file.readline().split()
	line2 = file.readline().split()
	line1 = [int(ele) for ele in line1]
	line2 = [int(ele) for ele in line2]
	ans = func(line1,line2)
	out.write("Case #"+str(i+1)+": "+str(ans))
	out.write("\n")
out.close()
file.close()
