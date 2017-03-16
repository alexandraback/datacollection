

file_in = open("A-large.in","r")
file_out = open("output.txt","w")

T = int(file_in.readline())
k = 0

while(k<T):
	P,Q = file_in.readline().split('/')
	P = float(P)
	Q = float(Q)

	gen = -1
	z = 0
	flag = -1

	if P==1 and Q==1:
		gen = 0

	else:
		for i in range(1,41):
			num = (P/Q) * 2**i
			if num >= 1:
				gen = i
				z = num - 1
				break
		for j in range(1,41):
			temp = z*(2**j)
			if temp == int(temp):
				flag = 1
				break
	print str(num)

	file_out.write("Case #" + str(k+1) + ": ")
	
	if (flag == 1):
		file_out.write(str(gen))
	elif P==1 and Q==1:
		file_out.write("0")
	elif flag == -1:
		file_out.write("impossible")
	
	file_out.write("\n")
	k+=1

file_in.close()
file_out.close()