inp = open ('2s.txt')
out = open ('2so.txt','w')
#inp = open ('2l.txt')
#out = open ('2lo.txt','w')
			
# impossible:
# grass in all 4 directions are higher
# ie. possible:
# every area is the hightest area in a lane		
			
count = 0
inp.readline()
size = inp.readline()
while size:
	size = size.split(' ')
	width = int(size[1])
	height = int(size[0])
	
	#data
	data = [x[:] for x in [[0]*width]*height]
	for i in range(0, height):
		data[i] = map(lambda x: int(x), inp.readline()[0:-1].split(' '))
		print data[i]
	
	#find max
	maxw = [0]*height
	maxh = [0]*width
	for i in range(0, height):
		maxw[i] = max(data[i])
		for j in range(0, width):
			maxh[j] = max(maxh[j], data[i][j])
#	print maxw
#	print maxh

	# find possiblility
	possible = True
	for i in range(0, height):
		for j in range(0, width):
			if data[i][j] == maxw[i] or data[i][j] == maxh[j]:
				continue
			else:
				possible = False
				print i,j,data[i][j]
				break
		if not possible:
			break

	possible = 'YES' if possible else 'NO'
	
	count += 1
	result = 'Case #' + str(count) + ': ' + possible
	print result
	out.write(result+'\n')
	size = inp.readline()
inp.close()
out.close()
	
	
	
	