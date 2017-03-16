INPUT = {
	'input': ('string', 'array')
}

TEST = ('''\
3
3
1 2
1 3
0
5
2 2 3
1 4
1 5
1 5
0
3
2 2 3
1 3
0
''','''\
Case #1: No
Case #2: Yes
Case #3: Yes
''')

def dfs(links, i, black):
	if i in black:
		return True
	for j in links[i]:
		if dfs(links, j, black):
			return True
	black.append(i)
	return False

def main(input):
	input = map(lambda x: map(lambda x: int(x) - 1, x[1:]), map(lambda x: x.split(' '), input))
	N = len(input)
	
	links = [[] for x in xrange(N)]
	roots = []
	
	
	for i,bs in enumerate(input):
		for b in bs:
			links[b].append(i)
		if len(bs) == 0:
			roots.append(i)
			
	for root in roots:
		black = []
		if dfs(links, root, black):
			return "Yes"
		
	return "No"