import re

with open('B-large.in') as f:
	data = f.readlines()

T = int(data[0])
result = ''
for i in range(T):
	v = 2
	t = 0
	t_row = data[i+1]
	row = re.findall(r'\d+\.\d+', t_row)
	C = float(row[0])
	F = float(row[1])
	X = float(row[2])
	
	while C/v+X/(v+F) < X/v:
		t += C/v
		v += F
	t += X/v
	result += 'Case #' + str(i+1) + ': '
	result += '{0:.7f}'.format(t)
	result += '\n'

with open('B-large.out', 'w') as f:
	f.write(result)