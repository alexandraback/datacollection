def sum_even_squares (s, e):
	e -= e%2;
	e = e/2;
	s -= 1;
	s -= s%2;
	s = s/2
	return 4*(e*(e+1)*(2*e+1))/6 - 4*(s*(s+1)*(2*s+1))/6

def sum_odd_squares (s, e):
	e -= 1-e%2
	s -= 1
	s -= 1-s%2
	return (e*(e+1)*(e+2))/6 - (s*(s+1)*(s+2))/6

file = open("sample.txt", "r");
tc = int(file.readline());
for i in range(1, tc+1):
	line = file.readline();
	temp = line.split(" ");
	r = int(temp[0]);
	p = int(temp[1]);
	if (r%2 == 0):
		#even
		s = 0
		e = 10**20
		while (e-s > 2):
			m = (s+e)/2;
			m -= 1-m%2;
			sum = sum_odd_squares(r, m);
			sum -= sum_even_squares(r, m);
			#print ("%d %d" % (sum, m))
			if (sum > p):
				e = m
			else:
				s = m;
		print ("Case #%d: %d" % (i, (s-r+1)/2))	
	elif (r % 2 == 1):
		#odd
		s = 0
		e = 10**20
		while (e-s > 2):
			m = (s+e)/2;
			m -= m%2;
			sum = sum_even_squares(r, m);
			sum -= sum_odd_squares(r, m);
			#print ("%d %d" % (sum, m))
			if (sum > p):
				e = m
			else:
				s = m;
		print ("Case #%d: %d" % (i, (s-r+1)/2))	
	#print ("Case #%d: %d" % (r, p))