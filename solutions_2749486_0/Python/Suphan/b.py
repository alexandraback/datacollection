import sys

if len(sys.argv) < 3:
	print 'input/output file name must be defined.'
	exit(1)

input_file = open(sys.argv[1])
output_file = open(sys.argv[2], 'w')
num = int(input_file.readline())

for i in range(num):
	input_ = input_file.readline().split()
	X = int(input_[0])
	Y = int(input_[1])
	ans = ''
	step = 1
	x, y = 0, 0
	if abs(X) < abs(Y):
		if X > 0:
			while x + step <= X:
				ans += 'E'
				x += step
				step += 1
		else:
			while x + step <= abs(X):
				ans += 'W'
				x += step
				step += 1
		if Y > 0:
			while y + step <= Y:
				ans += 'N'
				y += step
				step += 1
		else:
			while y + step <= abs(Y):
				ans += 'S'
				y += step
				step += 1
	else:
		if Y > 0:
			while y + step <= Y:
				ans += 'N'
				y += step
				step += 1
		else:
			while y + step <= abs(Y):
				ans += 'S'
				y += step
				step += 1
		if X > 0:
			while x + step <= X:
				ans += 'E'
				x += step
				step += 1
		else:
			while x + step <= abs(X):
				ans += 'W'
				x += step
				step += 1
	if X > 0:
		ans += ('WE' * (X - x))
	else:
		ans += ('EW' * (abs(X) - x))
	if Y > 0:
		ans += ('SN' * (Y - y))
	else:
		ans += ('NS' * (abs(Y) - y))

	output_file.write('Case #' + str(i + 1) + ': ' + ans + '\n')

input_file.close()
output_file.close()
