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
			return num2 
		ans+=1

# riddle #2
def solve_riddle2(input):
	input = input.rstrip()+'+'
	ans = 0
	for i in range(len(input)-1):
		if input[i]!=input[i+1]:
			ans+=1
	return ans

def start_of_section(section,k):
	return (section-1)*k

# returns the position that would be G if any of index:index+c (inclusive,non-inclusive) is G
def get_index_for(index,k,c):
	section = index
	c_eff = min([c,k,k-index+1])
	for i in range(index,c_eff+index-1):
		section = start_of_section(section,k)
		section += i+1
	if c_eff<c and c!=1:
		section = section + k**(c-1)*(index-1)
	return section

def get_positions(k,c):
	pos = [get_index_for(i,k,c) for i in range(1,k+1,c)]
	return pos

def get_positions_string(positions):
	stri = ''
	for i in positions:
		stri = stri + str(i) + ' '
	stri = stri[:-1]
	return stri

#riddle #4
def solve_riddle4(input):
	input = input.split()
	k = int(input[0])
	c = int(input[1])
	s = int(input[2])
	if(k>s*c):
		return 'IMPOSSIBLE'
	return get_positions_string(get_positions(k,c))

solve_riddle4('3 2 2')
# read the input
file = open(sys.argv[1])
output = open('output.txt', 'w')
lines = file.readlines()
# the number of cases.
n = int(lines[0])
cur_line = 1
# solve the riddle and write to the output file.
for i in range(n):
	answer = solve_riddle4(lines[i+1])
	output.write(output_format.format(i+1,answer))