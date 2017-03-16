fin = open("B-large.in","r")
fout = open("B-out-large","w")

T = int(fin.readline())

TC = fin.readlines()

total = 0
i = 0



for test in TC:
	i+=1
	test = map(int,test.split())
	s = test[1]
	p = test[2]
	result = 0
	for run in test[3:]:
		if run/3 >= p: 
			result += 1
		else: 
			if run%3 == 0:
				if run/3 > 0 and (run/3 + 1) >= p and s > 0:
					s -= 1
					result += 1
			elif run%3 == 1:
				if (run/3 + 1) >= p:
					result+=1
			elif run%3 == 2:
				if (run/3 + 1) >= p:
					result+=1
				elif (run/3 + 2) >= p and s > 0:
					s -= 1
					result += 1
					
	fout.write( "Case #" + str(i) + ": " + str(result) +'\n')
