from fractions import Fraction

def is_power2(num):
	'states if a number is a power of two'
	return num != 0 and ((num & (num - 1)) == 0)

for x in range (0,int(raw_input())):
	line = raw_input().split('/')
	num = int(line[0])
	den = int(line[1])
	f = Fraction(num,den)
	if not is_power2(f.denominator):
		print 'Case #%d: impossible' % (x+1)
		continue
	has_found = False
	for y in range(1,41):
		if f.numerator * (2 ** y) >= f.denominator:
			print 'Case #%d: %d' % (x+1,y)
			has_found = True
			break
	if not has_found:
		print 'Case #%d: impossible' % x+1