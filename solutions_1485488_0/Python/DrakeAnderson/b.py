from sys import stdin

ceilings = list()
floors = list()

t = int(stdin.readline()) + 1
for i in range(1, t):
    h, n, m = stdin.readline().split(" ")
    h = int(h)
    n = int(n)
    m = int(m)
    ceilings = list()
    times = list()
    traversed = list()
    for j in range(0, n):
        ceiling_row = list()
        time_row = list()
        traversed_row = list()
        lines = stdin.readline().strip().split(" ")
        for line in lines:
            ceiling_row.append(int(line))
            time_row.append(-1)
            traversed_row.append(False)
        ceilings.append(ceiling_row)
        times.append(time_row)
        traversed.append(traversed_row)
    floors = list()
    for j in range(0, n):
        floor_row = list()
        lines = stdin.readline().split(" ")
        for line in lines:
            floor_row.append(int(line))
        floors.append(floor_row)
    nodes = list()
    nodes.append((0, 0))
    while(nodes):
        x, y = nodes.pop(0)
        time = times[x][y]
        h_current = h - time * 10
        next_nodes = list()
        for a,b in [(x+1,y),(x-1,y),(x,y+1),(x,y-1)]:
            if not (a >= n or a < 0 or b >= m or b < 0):
                #intractables
                if not (ceilings[x][y] - floors[a][b] < 50 or ceilings[a][b] - floors[a][b] < 50):
                    if ceilings[a][b] - h_current >= 50:
                        additional_time = (1 if h_current - floors[x][y] >= 20 else 10)
                        next_nodes.append(((time + additional_time if time > 0 else 0), a, b))
                    else:
                        # you have to wait
                        additional_time = (50 - (ceilings[a][b] - h_current)) * 1.0 / 10
                        h_current_temp = h_current - additional_time * 10
                        additional_time += (1 if h_current_temp - floors[x][y] >= 20 else 10)
                        next_nodes.append((time + additional_time, a, b))
        next_nodes.sort()
        for time, x2, y2 in next_nodes:
            if times[x2][y2] < 0 or time < times[x2][y2]:
                times[x2][y2] = time
            if not traversed[x2][y2]:
                traversed[x2][y2] = True
                nodes.append((x2, y2))
    print "Case #%d: %f" % (i, times[n-1][m-1])
