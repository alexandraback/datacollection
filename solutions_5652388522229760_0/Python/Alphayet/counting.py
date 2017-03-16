import sys

filename = sys.argv[1]

with open(filename, 'r') as fh:
	T = int(fh.readline().strip())
	for t in range(T):
		n = int(fh.readline().strip())
		if n == 0:
			print "Case #%d: INSOMNIA" % (t+1)
		else:
			digit = [0] * 10
			new_n = n
			while sum(digit) < 10:
			    tmp_n = new_n
			    while tmp_n > 0:
			        digit[tmp_n % 10] = 1
			        tmp_n = tmp_n / 10
			    new_n = new_n + n
			print "Case #%d: %d" % (t+1, new_n - n)
