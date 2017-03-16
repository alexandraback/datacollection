import sys

input = str(sys.argv[1]).strip()
output = open(sys.argv[2], 'w')

def calc(S_max, audience):
	friends = 0
	clapping = 0
	for i in range(S_max + 1):
		S_i = int(audience[i])
		if clapping >= i:
			clapping += S_i
		else:
			add = i - clapping
			friends += add
			clapping += add + S_i
	return friends

with open(input) as f:
	content = f.readlines()

T = int(content[0].strip())

for case in range(1, T+1):
	line = content[case].strip().split()
	S_max = int(line[0])
	audience = line[1]
	result = calc(S_max, audience)
	output.write('Case #' + str(case) + ': ' + str(result) + '\n')
