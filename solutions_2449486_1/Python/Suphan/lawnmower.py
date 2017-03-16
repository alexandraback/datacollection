import sys
from collections import defaultdict

if len(sys.argv) < 3:
	print 'input/output file name must be defined.'
	exit(1)

input_file = open(sys.argv[1])
output_file = open(sys.argv[2], 'w')
num = int(input_file.readline())
for i in range(num):
	size = input_file.readline().strip().split()
	row = int(size[0])
	col = int(size[1])
	lawn = []
	for x in range(row):
		lawn.append(map(int, input_file.readline().strip().split()))

	count = defaultdict(int)
	for x in range(row):
		for y in range(col):
			count[lawn[x][y]] += 1
	heights = sorted(list(count))

	possible = True
	for h in heights:
		used = {}
		# check row
		for x in range(row):
			row_pos = True
			for y in range(col):
				if lawn[x][y] > h:
					row_pos = False
					break
			if row_pos:
				for y in range(col):
					if lawn[x][y] == h:
						used[(x, y)] = 1

		# check column
		for y in range(col):
			col_pos = True
			for x in range(row):
				if lawn[x][y] > h:
					col_pos = False
					break
			if col_pos:
				for x in range(row):
					if lawn[x][y] == h:
						used[(x, y)] = 1

		if len(used) < count[h]:
			possible = False
			break

	if possible:
		output_text = 'YES'
	else:
		output_text = 'NO'
	output_file.write('Case #' + str(i + 1) + ': ' + output_text + '\n')

input_file.close()
output_file.close()
