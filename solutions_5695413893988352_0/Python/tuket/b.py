import sys

tin = sys.stdin.read()
tin = tin.split()

nn = int(tin[0])

for kk in xrange(1, nn+1):
	
	res1 = ""
	res2 = ""
	
	w1 = tin[1 + 2 *(kk-1)]
	w2 = tin[2 + 2 *(kk-1)]
	
	e1 = w1.replace('?', '0')
	e2 = w2.replace('?', '0')
	
	b1 = e1
	b2 = e2
	b = abs(int(b1)-int(b2))
	
	e1 = list(e1)
	e2 = list(e2)
	
	end = False
	while not end:
		
		#print("".join(e1) + " " + "".join(e2))
		
		end = False
		for i in xrange(len(w2)-1, -1, -1):
			if w2[i] == '?':
				if e2[i] == '9':
					e2[i] = '0'
				else:
					e2[i] = str(int(e2[i])+1)
					end = True
					break
		if not end:
			end = True
			for i in xrange(len(w1)-1, -1, -1):
				if w1[i] == '?':
					if e1[i] == '9':
						e1[i] = '0'
					else:
						e1[i] = str(int(e1[i])+1)
						end = False
						break
		else:
			end = False
		
		if not end:
			ee1 = "".join(e1)
			ee2 = "".join(e2)
			if abs(int(ee1)-int(ee2)) < b:
				b1 = ee1;
				b2 = ee2;
				b = abs(int(ee1)-int(ee2))
		else:
			print("Case #" + str(kk) + ": " + str(b1) + " " + str(b2))
