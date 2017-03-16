Tc = input()

for T in range(1, Tc+1):
	L = input()
	f1 = [False]*L
	f2 = [False]*L
	m1 = []
	m2 = {}
	stars = 0
	cmpl = 0
	res = 0
	flag = False
	for i in range(0, L):
		sin = raw_input().split()
		a = int(sin[0])
		b = int(sin[1])
		m1.append((3000-b, a, i))
		if (b in m2):
			m2[b].append(i)
		else:
			m2[b] = [i]
	m1.sort()
	#print (m1)
	#print(m2)
	while (cmpl < L):
		next = 0
		pops = []
		for i in m2:
			if i > stars: 
				next = i
				break
			
			x = m2[i]
			pops.append(i)
			for j in x:
				
				f2[j] = True
				stars += 1
				res += 1
				if (f1[j] == False): 
					stars += 1 
				#print('%d cmpl stars: %d' % (j, stars))
				cmpl += 1
		for i in pops:
			m2.pop(i)
		if (cmpl == L): break
		k = 0
		#print (f1)
		#print (f2)
		flag2 = True
		while(flag2):
			flag2 = False
			for i in m1:
				if (f2[i[2]]):
					m1.remove(i)
					continue 
				if (i[1] > stars): continue
				stars+= 1
				#print('%d 1s stars: %d' % (i[1], stars))
				res += 1
				f1[i[2]] = True
				flag2 = True
				m1.remove(i)
				if (stars >= next):
					flag2 = False
				break
		if (stars < next):
			flag = True
			break
	y = ''
	if (flag): y = 'Too Bad'
	else: y = '%d' % res
	print('Case #%d: %s' % (T, y))
		
			
		