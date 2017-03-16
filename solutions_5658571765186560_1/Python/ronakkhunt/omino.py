tc = int(raw_input())

x = []
r = []
c = []

for i in range(tc):
	temp = raw_input()
	temp = temp.split(' ')

	x.append(int(temp[0]))
	r.append(int(temp[1]))
	c.append(int(temp[2]))

for i in range(tc):

	X = x[i]
	R = r[i]
	C = c[i]
	
	ans = True
	if X >= 7:
		ans = False
	elif X > R and X > C:
		ans = False
	elif R * C % X != 0:
		ans = False
	elif (X + 1) // 2 > min(R, C):
		ans = False
	elif X in (1, 2, 3):
		ans = True
	elif X == 4:
		ans = min(R, C) > 2
	elif X == 5:
		ans = not(min(R, C) == 3 and max(R, C) == 5)
	elif X == 6:
		ans = min(R, C) > 3

	if ans:
		print 'Case #'+str(i+1)+':', 'GABRIEL' 
	else:
		print 'Case #'+str(i+1)+':', 'RICHARD' 




