file_n = 'ds 160.in'
content = open(file_n , 'r').read().splitlines()
T, output   = int(content[0]), ''
for i in xrange(1, T + 1):
	#K, C, S =  map(int, content[i].split())
	s = content[i].strip()
	case = "Case #%d: " %i 
	current = s[0] 
	word = s[0]
	for i in xrange(1, len(s)):
		if s[i] >= word[0]:
			word = s[i] + word
		else:
			word = word +s[i]
	print word
	case += word
	output += case + '\n'
file_out = file_n.replace('.in','.out')
f = open(file_out, 'w')
f.write(output)
f.close()


