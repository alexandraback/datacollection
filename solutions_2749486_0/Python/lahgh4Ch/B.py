def walk(X, Y):
	pointStep = {(0, 0, 0): True}
	queue = [(0, 0, 0, '')] # x, y, step, walk
	while len(queue) > 0:
		point = queue.pop(0)
		x, y, step, w = point
		if x == X and y + step + 1 == Y:
			return w + 'N'
		if (x, y + step + 1, step + 1) in pointStep:
			pass
		else:
			pointStep[(x, y + step + 1, step + 1)] = True
			queue.append((x, y + step + 1, step + 1, w + 'N'))
		if x == X and y - step - 1 == Y:
			return w + 'S'
		if (x, y - step - 1, step + 1) in pointStep:
			pass
		else:
			pointStep[(x, y - step - 1, step + 1)] = True
			queue.append((x, y - step - 1, step + 1, w + 'S'))
		if x + step + 1 == X and y == Y:
			return w + 'E'
		if (x + step + 1, y, step + 1) in pointStep:
			pass
		else:
			pointStep[(x + step + 1, y, step + 1)] = True
			queue.append((x + step + 1, y, step + 1, w + 'E'))
		if x - step - 1 == X and y == Y:
			return w + 'W'
		if (x - step - 1, y, step + 1, w + 'W') in pointStep:
			pass
		else:
			pointStep[(x - step - 1, y, step + 1)] = True
			queue.append((x - step - 1, y, step + 1, w + 'W'))
	return ''


T = int(raw_input())
for t in range(T):
	line = raw_input()
	X, Y = line.split(' ')
	X = int(X)
	Y = int(Y)
	print 'Case #' + str(t + 1) + ':', walk(X, Y)
