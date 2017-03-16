
def number(n):
	if n == 0:
		return "INSOMNIA"
	seen = [False]*10
	count = 0
	x = n
	while True:
		for d in str(x):
			d = int(d)
			if not seen[d]:
				count += 1
				if count == 10:
					return x
			seen[d] = True
		x += n

output = []
with open('counting_input.txt') as f:
	t = int(f.readline())
	for i,line in enumerate(f):
		output.append("Case #%d: %s\n" % (i+1,str(number(int(line)))))

with open('counting_output.txt','w') as f:
	for line in output:
		print line,
		f.write(line)
		
