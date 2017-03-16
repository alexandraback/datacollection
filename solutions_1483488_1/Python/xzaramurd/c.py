fin = open("C-large.in","r")
fout = open("C-out","w")

T = int(fin.readline())

TS = fin.readlines()
i=0

for test in TS:
	i+=1
	test = map(int,test.split())
	A = test[0];
	B = test[1];
	result = 0;
	for n in range(A,B+1):
		s = str(n);
		min = n;
		add = True
		p = []
		for j in range(0,len(s)-1):
			s = s[len(s)-1] + s[:len(s)-1]
			num = int(s)
			if len(str(num)) < len(s): continue
			if num < A or num > B: continue
			if num > n and not num in p:
				p.append(num)

		if add and len(p) > 0: 
			#print str(n) + ": " + str(p)
			result += len(p)
	fout.write("Case #" + str(i) + ": " + str(result) + '\n')
