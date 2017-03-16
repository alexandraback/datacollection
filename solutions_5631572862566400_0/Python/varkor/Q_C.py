inputData = open("Q_C_input.txt", "r")
outputData = open("Q_C_output.txt", "w")
outputLines = []

def output (string):
	string = str(string)
	print(string)
	outputLines.append(string)

def case (x, y):
	output("Case #" + str(x) + ": " + str(y))

skip = True
i = 0
for (number, line) in enumerate(inputData.read().splitlines()[1:]):
	if skip:
		skip = False
		continue
	skip = True
	bffs = list(map(lambda x: int(x) - 1, line.split(" ")))
	nodes = set([i for i in range(len(bffs))])
	circle = 0
	indeps = {}
	while len(nodes) > 0:
		c = nodes.pop()
		path = [c]
		while True:
			f = bffs[c]
			if f in path:
				nc = 0
				if bffs[path[-1]] == path[-2]:
					nc = len(path)
					key = (path[-2], path[-1])
					if key not in indeps or nc > indeps[key]:
						indeps[key] = nc
				else:
					nc = len(path) - path.index(f)
				circle = max(circle, nc)
				break
			else:
				path.append(f)
				c = f
	if len(indeps) >= 2:
		sm = 0
		skip = set()
		for (a, b) in indeps:
			if (a, b) in skip:
				continue
			if (b, a) in indeps:
				sm += indeps[(a, b)] + indeps[(b, a)] - 2
				skip.add((b, a))
			else:
				sm += indeps[(a, b)]
		circle = max(circle, sm)
	i += 1
	case(i, circle)

outputData.write("\n".join(outputLines))
inputData.close()
outputData.close()