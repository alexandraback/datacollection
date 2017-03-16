price = 0
rentable = 0
limit = 0
aug = 0

def compute_time(income):
	time = 0
	while (limit-price)/income > rentable:
		time = time + price/income
		income = income+aug	
	return time+limit/income

nb = raw_input()


for i in xrange(int(nb)):
	s = raw_input()
	tmp = map(float,s.split())
	
	price = tmp[0]
	rentable = tmp[0]/tmp[1]
	limit = tmp[2]
	aug = tmp[1]
	print("Case #%d: %.7f" % (i+1,compute_time(2)))

