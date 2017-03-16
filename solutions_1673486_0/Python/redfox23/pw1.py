import sys
input = open('A-small-attempt0.in', 'r')
output = open('pw.txt', 'w')

sTest = input.readline()
test = int(sTest)
l = []



for tc in range(test):
	del l[:]
	sLine = input.readline()
	l = sLine.split()
	a = int(l.pop(0))
	b = int(l.pop(0))
		
	sLine = input.readline()
	l = sLine.split()
	p = [0]*a
	for i in range(a):
		p[i] = float(l.pop(0))
		
		

	output.write('Case #')
	output.write(str(tc+1))
	output.write(': ')
		
	#---start process
	again = b + 1
	min = sys.float_info.max -1
	for numback in range(0,a): #back til 1 char left
		pp = 1
		acc = 0
		for lamechar in range(0,a):
			if lamechar>0:
				pp = pp * p[lamechar-1] #=p[0]...p[lamechar-1]
			up = pp * (1 - p[lamechar])
			if numback>=(a-lamechar): #right 1st time
				charleft = b-(a-numback)
				key = numback + charleft + 1
			else: #wrong
				charleft = b-(a-numback)
				key = numback + charleft + 1 + again
			acc += key * up
		pp = pp*p[a-1]
		charleft  = b-(a-numback)
		key = numback + charleft + 1
		acc += pp * key
		if acc < min:
			min = acc

		
	#enter right away
	key = 1 + again

	if key < min:
		min = key
	
	#---end process
	
	output.write("%.6f" % min)
	output.write('\n')

input.close()
output.close()