import itertools


NAME = 'fashion_police'
input_file = NAME + '.in'
output_file = NAME + '.out'


with open(input_file, 'rb') as inf, open(output_file, 'wb') as outf:
	t = int(inf.readline())
	for i in xrange(1, t+1):
		j, p, s, k = map(int, inf.readline().split())
		plan = []
		# days = min(outfit_choices, garment_tolerance)
		outfit_choices = j*p*s
		garment_tolerance = j*p*k
		# produce actual allowable combos
		if outfit_choices <= garment_tolerance:
			days = outfit_choices
			ways = itertools.product(
				xrange(1, j+1), xrange(1, p+1), xrange(1, s+1))
		else:
			days = garment_tolerance
			# ways = itertools.product(
			ways = []
			for a in xrange(1, j+1):
				for b in xrange(1, p+1):
					for c in xrange(1, 1+k):
						ways.append((a, b, (a+b+c)%s+1))
		# build output string
		outl = 'Case #{0}: {1}\n{2}\n'.format(i, 
											  days,
										 	  '\n'.join(
										 		' '.join(map(str, way)) for way in ways))
		outf.write(outl)