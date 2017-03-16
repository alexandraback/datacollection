f = open('A-large.in', 'r')
g = open('output', 'w')

n = int(f.readline().replace('\n', ''))
counter = 0


def solve(lines):
	node_list = []
	for i in xrange(num + 1):
		node_list.append([])
	
	count = 0
	for in_node in lines:
		count += 1
		for node in in_node:
			node_list[node] += [count]
	for i in xrange(1, len(node_list)):
		all_dest = []
		queue = [node for node in node_list[i]]
		while len(queue) > 0:
			curr_node = queue.pop()
			if curr_node in all_dest:
				g.write("Case #" + str(counter+1) + ": " + 'Yes\n')
				return
			else:
				all_dest.append(curr_node)
			for node in node_list[curr_node]:
				queue.append(node)
	g.write("Case #" + str(counter+1) + ": " + 'No\n')
	
while counter < n:
	line = f.readline()
	if '\n' in line:
		line = line[:-1]
		
	num = int(line)
	count = 1	
	
	lines = []
	while count <= num:
		line = f.readline()			
		if '\n' in line:
			line = line[:-1]
		in_node = [int(node) for node in line.split(' ')]
		in_node = in_node[1:]
		lines.append(in_node)
		count += 1
	solve(lines)
	counter += 1

f.close()
g.close()