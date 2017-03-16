def solve_problem(X,Y):
	path= ''
	x= 0
	y= 0
	n= 1
	while x!=X:
		if X>x:
			path+= 'W'
			x-= n
			n+= 1
			path+= 'E'
			x+= n
		else:
			path+= 'E'
			x+= n
			n+= 1
			path+= 'W'
			x-= n
		n+= 1
	while y!=Y:
		if Y>y:
			path+= 'S'
			y-= n
			n+= 1
			path+= 'N'
			y+= n
		else:
			path+= 'N'
			y+= n
			n+= 1
			path+= 'S'
			y-= n
		n+= 1
	return path

file= open('pogo.in')
input= file.read().split('\n')
file.close()

T= int(input[0])
for i in range(1,T+1):
	line= input[i].split()
	X= int(line[0])
	Y= int(line[1])
	print 'Case #' + str(i)	+ ': ' + solve_problem(X,Y)