lines = open('input.txt','r').readlines()
T = int(lines[0])
for i in range(1,T+1):
	line = lines[i].strip()
	arr = line.split()
	A = int(arr[0])
	B = int(arr[1])
	res = 0	
	for n in range(A,B):
		nn = str(n)
		mmap = set()
		for j in range(len(nn)):
			mm = nn[j:len(nn)] + nn[0:j]
			if mm[0] == '0':
				continue
			m = int(mm)
			if n < m and m <= B:
				mmap.add(m)		
		res += len(mmap)	
	print "Case #" + str(i) + ": "+ str(res)