import sys



n = int(input())

for i in range(n):
	strline = raw_input()

	bb = ''

	for c in strline:
		if bb == '':
			bb = c
		elif bb[0] > c:
			bb = bb+c
		else:
			bb = c+bb

	

	strA = 'Case #%d: '%(i+1)
	strB = bb

	printstr = strA + strB
	print(printstr)
