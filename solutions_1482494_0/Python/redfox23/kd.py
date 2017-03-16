input = open('B-small-attempt0.in', 'r')
output = open('kingdom.txt', 'w')

sTest = input.readline()
test = int(sTest)
l = []



for tc in range(test):
	del l[:]
	n = int(input.readline())
	a = [0]*n
	b = [0]*n
	mark = [2]*n
	for i in range(n):
		sLine = input.readline()
		l = sLine.split()
		a[i] = int(l.pop(0))
		b[i] = int(l.pop(0))
		
	#print(n)
	output.write('Case #')
	output.write(str(tc+1))
	output.write(': ')
	
	#---start process
	count = 0
	aim = n*2
	play = 0
	print(n)
	print(a)
	print(b)
	while count < aim:
		got = False
		for i in range(n):
			if mark[i] == 2:
				if count>=b[i]:#1st rate2
					count = count + 2
					mark[i] = 0
					got = True
					play = play + 1
					break
			elif mark[i] ==1:
				if count>=b[i]:#2nd rate2
					count = count + 1
					mark[i] = 0
					got = True
					play = play + 1
					break
		if got:
			continue
		#mina = 5000
		maxb = 0
		ti = -1
		for i in range(n):
			if mark[i] == 2:
				if count >= a[i]:
					if b[i] > maxb:
						ti = i
						maxb = b[i]
		if ti == -1:
			break
		mark[ti] = 1
		count = count + 1
		play = play + 1
	#---end process
	if count < aim:
		output.write("Too Bad")
	else:
		output.write(str(play))
	#output.write(str(count))
	output.write('\n')

input.close()
output.close()