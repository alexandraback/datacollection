import math

N = 0
M = 0
graph = []
zips = []
opt_zips = []

def walk(current_zips, i, visited):
    global N, M, graph, zips, opt_zips

    #print current_zips
    #print i
    #print visited
    #print '----'

    # All cities reached?
    if len(visited) == N:
        j = 0
        for j in xrange(N):
            if current_zips[j] > opt_zips[j]:
                return
            if current_zips[j] < opt_zips[j]:
                break;
        opt_zips = current_zips
        return

    # Does this path could be optimal?
    j = 0
    for j in xrange(len(current_zips)):
        if current_zips[j] > opt_zips[j]:
            return
        if current_zips[j] < opt_zips[j]:
            break

    # Try to step forward from current location.
    for j in xrange(N):
        if j not in visited:
            new_current_zips = list(current_zips)
            new_current_zips.append(zips[j])
            new_visited = set(visited)
            new_visited.add(j)
            walk(new_current_zips, j, new_visited)

def solve(input_file):
    global N, M, graph, zips, opt_zips
    case = input_file.readline().split(' ')
    N = int(case[0])
    M = int(case[1])
    opt_zips = [100000] * N

    # Read zips.
    zips = []
    for i in xrange(N):
        line = input_file.readline()
        zips.append(int(line))

    # Read graph.
    graph = [] * N
    for i in xrange(N):
        graph.append([])
    for i in xrange(M):
        path = input_file.readline().split(' ')
        start = int(path[0]) - 1
        finish = int(path[1]) - 1
        graph[start].append(finish)
        graph[finish].append(start)

    # Start from each city.
    for i in xrange(N):
        walk([zips[i]], i, {i})

    # Return result.
    final_zip = ''
    for i in xrange(N):
        final_zip += str(opt_zips[i])
    return final_zip

input_file = open('C.in', 'r')
output_file = open('C.out', 'w')

number_of_cases = int(input_file.readline())
print 'number_of_cases:', number_of_cases

for i in xrange(number_of_cases):
    solution = solve(input_file)
    output_str = 'Case #' + str(i + 1) + ': ' + str(solution)
    print output_str
    output_file.write(output_str + '\r\n')

print "Done!!!"
