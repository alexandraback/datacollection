file = open("input6.txt")
t = file.readline()
out = open("outputfinal66.txt","w")
array = []
for i in range(0,int(t)):
	case = file.readline()
	cases = case.split()
	n = int(cases[0])
	print n
	tests = cases[1:]
	sum = 0
	for ele in tests:
		sum = sum+int(ele)
	newsum = (sum+sum)/n
	print sum
	print newsum
	out.write("Case #"+str(i+1)+": ")
	print tests
	elesum = 0
	for ele in tests:
		if int(newsum)-int(ele) <0:
			n=n-1
		else:
			elesum = elesum + int(ele)
	print elesum
	newsum = float(elesum+sum)/n
	print newsum
	v=0
	for ele in tests:
		if (int(newsum) - int(ele))<0:
			out.write(str(0.00)+ " ")
			
		else:
			v = v+ ((float(newsum)-float(ele))*100.00)/sum
			out.write(str(((float(newsum)-float(ele))*100.00)/sum)+" ")
	print "v is ",v
	out.write("\n")
out.close()
file.close()