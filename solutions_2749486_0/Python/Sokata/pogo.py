##libraries function
import time, bisect

def a_star(start, successors, is_goal, cost):
    #start is a tuple
    #successors return a list of (action, state)
    #is_goal takes a state and return boolean
    #cost takes a path (state, action, state) and returns a [cost + heuristic, path]

    #costs must be negative to allow proper pop of the frontier
    if is_goal(start): return [start]
    explored = {}
    frontier = [cost((start,))]
    while frontier:
        path = frontier.pop(0)[1]
        if path[-1] in explored:
            continue
        explored[path[-1]] = cost(path)
        for new in successors(path[-1]):
            path2 = path + new
            if path2[-1] in explored:
                continue
            if is_goal(path2[-1]):
                return path2
            else:
                temp = cost(path2)
                frontier.insert(bisect.bisect_right(frontier, temp), temp)
    return None

##custom file name
file_n = 'B-small-attempt0'

##template
input = open(file_n + '.in', 'r')
output = open(file_n + '.out', 'w')

n_case = int(input.readline())

start = time.clock()

for z in range(1, n_case+1):

	[X, Y] = map(int, input.readline().split(' '))

	def goal(state):
		(n, x, y) = state
		return X == x and Y == y

	def successors(state):
		(n, x, y) = state
		return [('N', (n+1, x, y+n+1)),
				('S', (n+1, x, y-n-1)),
				('W', (n+1, x-n-1, y)),
				('E', (n+1, x+n+1, y))]

	def cost(path):
		(n, x, y) = path[-1]
		c = len(path[1::2])
		dx = abs(X - x)
		while dx > 0:
			c += 1
			n += 1
			dx -= n + 1
		dy = abs(Y - y)
		while dy > 0:
			c += 1
			n += 1
			dy -= n + 1
		return [c, path]

	result = a_star((0, 0, 0), successors, goal, cost)[1::2]
	result = ''.join(result)

	assert(0 < len(result) <= 500)

	output.write('Case #%s: %s\n' % (z, result))

output.close()

print "Done in %s seconds" % (time.clock() - start)
