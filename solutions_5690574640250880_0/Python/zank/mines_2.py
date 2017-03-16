import copy

def free_count(fields):
	width, height = len(fields[0]), len(fields)
	count = 0
	for x in range(width):
		for y in range(height):
			if fields[y][x] == '.':
				count += 1
	return count

def get_free_point(fields):
	width, height = len(fields[0]), len(fields)
	for x in range(width):
		for y in range(height):
			if fields[y][x] == '.':
				return {'x': x, 'y': y}

def explore(x, y, fields):
	width, height = len(fields[0]), len(fields)
	fields = copy.deepcopy(fields)

	def neighbour_points(x, y):
		w, h = len(fields[0]), len(fields)
		points = []
		for dx in range(-1, 2):
			for dy in range(-1, 2):
				if not (dx == 0 and dy == 0) and x + dx >= 0 and x + dx < w and y + dy >= 0 and y + dy < h:
					points.append({'x': x + dx, 'y': y + dy})
		return points

	def number_of_neighbour_mines(x, y):
		count = 0
		for point in neighbour_points(x, y):
			if fields[point['y']][point['x']] == '*':
				count += 1
		return count

	def explore_recursion(x, y):
		if fields[y][x] == '.':
			fields[y][x] = '1'
			if number_of_neighbour_mines(x, y) == 0:
				for neighbour in neighbour_points(x, y):
					explore_recursion(neighbour['x'], neighbour['y'])
	
	explore_recursion(x, y)
	return fields

def create_fields(width, height, mine_count):
	fields = {i: {j: '.' for j in range(width)} for i in range(height)}

	current_mine_count = 0

	row = 0
	column = 0
	while current_mine_count < mine_count:
		if width - column >= height - row:
			for i in range(row, height):
				if current_mine_count + 1 == mine_count and i + 2 == height:
					fields[row][column + 1] = '*'
				else:
					fields[i][column] = '*'
				current_mine_count += 1
				if current_mine_count == mine_count: return fields
			column += 1
		else:
			for i in range(column, width):
				if current_mine_count + 1 == mine_count and i + 2 == width:
					fields[row + 1][column] = '*'
				else:
					fields[row][i] = '*'
				current_mine_count += 1
				if current_mine_count == mine_count: return fields
			row += 1

	return fields

def calculate(width, height, mine_count):
	fields = create_fields(width, height, mine_count)
	free_point = get_free_point(fields)
	if free_count(explore(width - 1, height - 1, fields)) > 0:
		return None

	fields[height - 1][width - 1] = 'c'
	return fields

def draw(matrix):
	for i in range(len(matrix)):
		print(' '.join(list(matrix[i].values())))

n = int(input())
for i in range(n):
	h, w, m = [int(x) for x in input().split(' ')]
	result = calculate(w, h, m)
	print('Case #' + str(i + 1) + ':')
	if result is not None:
		draw(result)
	else:
		print('Impossible')