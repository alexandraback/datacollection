import sys
input = sys.stdin.readlines()

T = int(input[0][:len(input[0])-1])

for t in range(1, T+1):
	AB = input[2*(t-1) + 1]
	if AB[len(AB)-1] == '\n':
		AB = AB[:len(AB)-1]
	[A,B] = map(int, AB.split(' '))

	ps = input[2*(t-1) + 2]
	if ps[len(ps)-1] == '\n':
		ps = ps[:len(ps)-1]
	p = map(float,ps.split(' '))

	tmp = 1
	pcomp = []
	for i in p:
		tmp *= i 
		pcomp.append(tmp)

	deleteallExp = (A + B + 1)

	continueExp = (B - A + 1)*pcomp[A-1] + (B - A + 1 + B + 1)*(1 - pcomp[A-1])

	giveupExp = (1 + B + 1)

	otherExps = [(A - (i+1) + B - (i+1) + 1)*pcomp[i] + (A - (i+1) + B - (i+1) + 1 + B + 1)*(1 - pcomp[i]) for i in range(0, A)]

	ans = min(deleteallExp, continueExp, giveupExp, min(otherExps))

	ans = str(ans)

	ans = ans.split('.')
	inte = ans[0]
	try:
		floate = ans[1]
	except:
		floate = ""
	floate += '0'*(6-len(floate))
	try:
		if floate[6]>='5':
			floate = floate[:5]+str(int(floate[5])+1)
		else:
			floate = floate[:6]
	except:
		floate = floate[:6]

	print 'Case #' + str(t) + ': ' + inte+'.'+floate
