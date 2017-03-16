sum_cache = {}
comb_cache = {}

def solve(number,position):
	x,y = position
	s = abs(x)+y
	number_to_complete = (s+1)*(s+2)/2
	if number >= number_to_complete:
		return 1.0
	number_to_not_complete = s*(s-1)/2
	if number_to_not_complete >= number:
		return 0.0
	value_to_go = number - number_to_not_complete
	if x == 0:
		if value_to_go >= 2*y+1:
			return 1.0
		return 0.0
	if value_to_go - s -y >0:
		return 1.0
	return ((2.0)**value_to_go-sum_binomials(value_to_go,y))/(2.0)**value_to_go


def sum_binomials(value,y):
	if y<0:
		return 0.0
	if (value,y) not in sum_cache:
		sum_cache[(value,y)] = comb(value,y)+sum_binomials(value,y-1)
	return sum_cache[(value,y)]

def comb(value,y):
	if y == 0:
		return 1
	if (value,y) not in comb_cache:
		comb_cache[(value,y)] = comb(value,y-1)*(value-y+1)/y
	return comb_cache[(value,y)]


number_of_cases = int(raw_input())
for n in xrange(1,number_of_cases+1):
	m, x, y = [int(l) for l in raw_input().split(" ")]
	print "Case #"+str(n)+": "+str(solve(m,(x,y)))