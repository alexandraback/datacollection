import math

for case in xrange(input()):
	sol = ''
	num, dem = map(int, raw_input().split('/'))
	resto = dem % num
	sol = ''
	if (resto == 0):
		temp = dem / num
		i = 1
		ans = 2
		while (ans < temp):
			ans = ans*2
			i+=1
		if (ans == temp):
			sol = str(i)
		else:
			sol = 'impossible'
	else:
		sol = 'impossible'

	print 'Case #%d: %s' % (case+1, sol)
