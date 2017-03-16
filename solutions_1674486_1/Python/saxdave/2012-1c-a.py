#!/usr/bin/python

def diamond(graph, base):
	path = [False] * len(graph)
	path[base] = True
	check = [base]

	i = 0

	while i < len(check):
		for parent in graph[check[i]]:
			if path[parent]:
				return True

			else:
				path[parent] = True
				check.append(parent)

		i += 1

	return False


# let's jam!
in_file = open('2012-1c-a.in', 'r')
tests = int(in_file.readline())
out_file = open('2012-1c-a.out', 'w')

for test in range(1, tests + 1):
	classes = int(in_file.readline())
	graph = [None] * classes

	for i in range(classes):
		data = map(int, in_file.readline().strip().split(' '))
		graph[i] = map(lambda j: j - 1, data[1:])

	for base in range(classes):
		if diamond(graph, base):
			result = 'Yes'
			break

	else:
		result = 'No'

	output = 'Case #%d: %s\n' % (test, result)
	out_file.write(output)

out_file.close()
in_file.close()
