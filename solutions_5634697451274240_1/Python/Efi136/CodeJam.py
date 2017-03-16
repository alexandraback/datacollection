import sys
import os

output_format = 'Case #{0}: {1}\n'
# riddle #1
def solve_riddle(input):
	seen = []
	if input=='0' or input=='0\n':
		return 'INSOMNIA'
	ans = 1
	num = input
	int_input = int(input)
	while True:
		num = str(int_input*ans)
		for i in range(len(num)):
			if not num[i] in seen:
				seen.append(num[i])
		if len(seen)>=10:
			return num
		ans+=1

# riddle #2
def solve_riddle2(input):
	input = input.rstrip()+'+'
	ans = 0
	for i in range(len(input)-1):
		if input[i]!=input[i+1]:
			ans+=1
	return ans

# read the input
file = open(sys.argv[1])
output = open('output.txt', 'w')
lines = file.readlines()
# the number of cases.
n = int(lines[0])
cur_line = 1
# solve the riddle and write to the output file.
for i in range(n):
	answer = solve_riddle2(lines[i+1])
	output.write(output_format.format(i+1,answer))