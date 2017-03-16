from fractions import Fraction

f = open('A-large.in', 'rb')
g= open('output', 'wb')

dic = {2**i:i for i in xrange(1,42)}
key = [Fraction(1,2**i) for i in xrange(1,41)]

N = int(f.next())

def solve(fract):
	ret = 0
	for x in key:
		if fract == Fraction(0,1):
			break
		if fract >= x:
			if dic.get(fract.denominator):
				if ret == 0:
					ret = dic.get(x.denominator)
			fract = fract - x
	if ret != 0 and fract == Fraction(0,1):
		return str(ret)
	else:
		return "impossible"
	

for case in xrange(N):
	frac = f.next()
	print frac
	[a,b]= frac.split('/')
	if b == '':
		g.write('Case #' + str(case + 1) + ': ' + 'impossible' + '\n')
		continue
	fr = Fraction(int(a), int(b))
	g.write('Case #' + str(case + 1) + ': ' + solve(fr) + '\n')


