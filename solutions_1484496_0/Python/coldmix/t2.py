def listsum(l):
	sum = 0
	for ele in l:
		sum = sum+ele
	return sum

file = open("input3.txt")
t = file.readline()
out = open("small3.txt","w")
for i in range(0,int(t)):
	out.write("Case #"+str(i+1)+":\n")
	l = file.readline()
	l = l.split()
	n = int(l[0])
	x = [int(ele) for ele in l[1:]]
	func = lambda x: [[y for j, y in enumerate(set(x)) if (i >> j) & 1] for i in range(2**len(set(x)))]
	f = func(x)
	dict = {}
	for ele in f:
		sum = listsum(ele)
		if sum in dict:
			for ele2 in dict[sum]:
				out.write(str(ele2)+" ")
			out.write("\n")
			for ele2 in ele:
				out.write(str(ele2)+" ")
			out.write("\n")
			flag=True
			break
		else:
			dict[sum] = ele
	if flag == False:
		out.write("impossible")
