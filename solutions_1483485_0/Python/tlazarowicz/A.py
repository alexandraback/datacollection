#!C:\Python27\python

char_translator = {' ': ' ', 'a': 'y', 'c': 'e', 'b': 'h', 'e': 'o', 'd': 's', 'g': 'v', 'f': 'c', 'i': 'd', 'h': 'x', 'k': 'i', 'j': 'u', 'm': 'l', 'l': 'g', 'o': 'k', 'n': 'b', 'q': 'z', 'p': 'r', 's': 'n', 'r': 't', 'u': 'j', 't': 'w', 'w': 'f', 'v': 'p', 'y': 'a', 'x': 'm', 'z': 'q'}

inp = file('A.input', 'r')
out = file('A.output', 'w')

num_cases = int(inp.readline())

for i_case in range(1, num_cases+1):
	testcase = inp.readline().strip()
	result = ''
	
	for char in testcase:
		result = result + char_translator[char]
	
	output = "Case #%d: %s" % (i_case, result)
	print output
	out.write(output + '\n')