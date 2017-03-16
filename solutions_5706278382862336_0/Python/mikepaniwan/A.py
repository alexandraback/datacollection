from fractions import Fraction
import math

n = int(raw_input())

for i in xrange(n):
	child = map(int,raw_input().split('/'))
	count = 0

	found = True

	if child[1]%2 != 0:
		found = False
	else :
		delta = str(Fraction(child[0],child[1]))
		sed = int(delta.split('/')[0])
		fc = int(delta.split('/')[1])
		check = str(math.log(fc,2)).split('.')

		if check[1] == '0':
			count = int(check[0])
		else :
			found = False

			
	print "Case #" + str(i+1) + ":",
	if found:
		count -= math.floor(math.log(sed,2))
		print int(count)
	else :
		print 'impossible'
		
