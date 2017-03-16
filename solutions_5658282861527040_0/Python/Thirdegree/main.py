def do(num1, num2, num3):
	temp = 0
	for i in xrange(num1):
		for j in xrange(num2):
			if i&j < num3:
				temp += 1
	return temp

with open("B-small-attempt0.in") as a:
	in_file = a.read().split('\n')

with open("output", 'w') as o: 
	for line, k in zip(in_file[1:], xrange(1, len(in_file[1:])+1)):
		in_line = map(int,line.split())
		num = do(*in_line)
		o.write("Case #%d: %d\n"%(k, num))