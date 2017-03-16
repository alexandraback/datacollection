f = open('large1.in')
T = int(f.readline().strip())

for k in range(T):
	original = f.readline()
	new = [original[0]]
	front = ord(original[0])
	for i in range(len(original)-2):
		num = ord(original[i+1])
		if num >= front:
			front = num
			new.insert(0,original[i+1])
		else:
			new.append(original[i+1])
	final = ''.join(new)
	print "Case #%d: %s" %(k+1, final)
		