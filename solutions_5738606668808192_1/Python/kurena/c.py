testcase = input()
for i in range(testcase):
	print "Case #"+str(i+1)+":"
	N,J=map(int,raw_input().split())
	j = 0
	n = 0
	while n<J:
		j += 1
		a2 = 0
		a7 = 0
		l2 = [(x+1)%2+1 for x in range(N-2)]
		l7 = [(x+1)%2*5+1 for x in range(N-2)]
		t = list(format(j,"b"))
		for k in range(len(t)):
			a2 += l2[k]*int(t[k])
			a7 += l7[k]*int(t[k])
		m = sum(map(int,t))
		if m%2!=0 or (m+2)%3!=0 or a2%3!=0 or a7%7!=0: continue
		b = "1"+"0"*(N-len(t)-2)+format(j,"b")+"1"
		print b,3,2,3,2,7,2,3,2,3
		n += 1
