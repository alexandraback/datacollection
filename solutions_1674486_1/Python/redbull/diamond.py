f = open("A-large.in", "r")
out = open("out", "w")

count = 0
flag = 0
case = 0
for line in f:
	if count == 0:
		T = int(line.split()[0])
		flag = 1
		count = 1
	elif flag == 1:
		#print line
		N = int(line.split()[0])
		Q = []
		A1 = [[i + 1,[]] for i in range(N)]
		A2 = [[i + 1,[]] for i in range(N)]
		i = 0
		V = []
		flag = 2
		case += 1
	elif flag == 2:
		s = line.split()[1:]
		for k in range(len(s)):
			s[k] = int(s[k])
		#print line
		A1[i][1].extend(s)
		i += 1
		for val in s:
			A2[val-1][1].append(i)
		if i == N:
		#	print A1
		#	print A2
			req_set = []
			for t in A2:
				if len(t[1]) == 0:
					req_set.append(t[0])
		#	print "req_Set" ,req_set
			for val in req_set:
				V = []
				V.append(val)
				Q.extend(A1[val - 1][1])
				ans = "No"
		#		print Q
				
				while(Q):
		#			print "Queue",Q
		#			print "visited",V
					temp = Q.pop(0)
					if temp in V:
						ans = "Yes"
						break
					else:
						Q.extend(A1[temp-1][1])
						V.append(temp)
		#				print V
				if ans == "Yes":
					break
			out.write("Case #"+str(case)+": "+ans+"\n")
		#	print "##########  " + ans
			flag = 1
f.close()
out.close()

