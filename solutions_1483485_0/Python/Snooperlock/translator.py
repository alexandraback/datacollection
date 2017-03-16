import sys

num_case = int(sys.stdin.readline())
map = {'a': 'y', 'b': 'h', 'c': 'e', 'd': 's', 'e': 'o', 'f': 'c', 'g': 'v', 'h': 'x', 'i': 'd', 'j': 'u', 'k': 'i', 'l': 'g', 'm': 'l', 'n': 'b', 'o': 'k', 'p': 'r', 'q':'z', 'r': 't', 's': 'n', 't': 'w', 'u': 'j', 'v': 'p', 'w': 'f', 'x': 'm', 'y': 'a', 'z': 'q', ' ': ' '}

for cur_case in range(1, num_case+1):
	src = list(sys.stdin.readline().strip('\n'))
	index = 0
	for l in src:
		src[index] = map[l]
		index = index + 1
	
	# print out final result
	file = open('output.txt', 'a')
	file.write('Case #%d: %s\n'%(cur_case, ''.join(src)))