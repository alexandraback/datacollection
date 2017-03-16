from math import pow
import sys

graph = []
ways = []
visiting = []
buildings, goal = 0, 0
def dfs(i, ways_to_this):
    if ways[buildings-1] > goal:
        return
    ways[i] += ways_to_this
    visiting[i] = True
    for v in range(0, buildings):
        if v != i and graph[i][v] == '1':
            if visiting[v]:
                ways[buildings-1] = goal+1
                return
            dfs(v, ways_to_this)
    visiting[i] = False

tests = int(input())
for test_case in range(1, tests+1):
    print("Case #" + str(test_case) + ": ", end="")
    buildings, goal = input().split()
    buildings = int(buildings)
    goal = int(goal)
    graph = ['0'*buildings]*buildings
    format_string = '0' + str((buildings-1)*(buildings-2)+1) + 'b'
    solved = False
    print("test", test_case, file=sys.stderr)
    print(int(pow(2, 1+(buildings-1)*(buildings-2))), file=sys.stderr)
    for i in range(0, int(pow(2, 1+(buildings-1)*(buildings-2)))):
        formatted_i = format(i, format_string)
        if i%100000 == 0:
            print(i, file=sys.stderr)
        invalid_graph = False
        graph[0] = '0' + formatted_i[0:buildings-1]
        for j in range(1, buildings-1):
            graph[j] = '0' + formatted_i[j*(buildings-2)+1:(j+1)*(buildings-2)+1]
            graph[j] = graph[j][0:j] + '0' + graph[j][j:]
        ways = [0]*(buildings)
        visiting = [False]*(buildings)
        dfs(0, 1)
        if ways[buildings-1] == goal:
            solved = True
            print('POSSIBLE')
            for s in graph:
                print(s)
            break
    if not solved:
        print('IMPOSSIBLE')
