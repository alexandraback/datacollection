from collections import deque

f = open('/home/useruser/datacollection/input/1485488_0.in' ,'r')
g = open('/home/useruser/datacollection/solutions_1485488_0/Python/mdragus/output.txt' ,'w')

ans = ""

t = int(f.readline().strip())


def wait_time(floor1,ceiling1,floor2,ceiling2,water_height):
    if ceiling2 - floor2 < 50:
        return -1
    if ceiling2 - floor1 < 50: 
        return -1
    if ceiling1 - floor2 < 50:
        return -1
    if ceiling2 - water_height >= 50:
        return 0
    return 0.1 * (50 - ceiling2 + water_height)

for nrt in range(t):
    el = f.readline().split()
    H = int(el[0])
    n = int(el[1])
    m = int(el[2])
    ceilings = []
    floors = []
    for i in range(n):
        el = f.readline().split()
        ceilings.append([int(x) for x in el])
    for i in range(n):
        el = f.readline().split()
        floors.append([int(x) for x in el])
    
    costs = [[10000000 for x in range(m)] for x in range(n)]
    costs[0][0] = 0.0
    queue = deque([(0,0,0)])
    move_dir = [[1,0],[0,1],[-1,0],[0,-1]]
    while(len(queue)):
        cur_state = queue.popleft()
        pozx = cur_state[0]
        pozy = cur_state[1]
        for direct in move_dir:
            new_pozx = pozx + direct[0]
            new_pozy = pozy + direct[1]
            if new_pozx < 0 or new_pozx >= n or new_pozy < 0 or new_pozy >=m:
                continue
            cur_wait = wait_time(floors[pozx][pozy],ceilings[pozx][pozy],\
                floors[new_pozx][new_pozy],ceilings[new_pozx][new_pozy],\
                max(0,H - 10 * costs[pozx][pozy]))
            if cur_wait == -1:
                continue
            cur_cost = cur_wait + costs[pozx][pozy]
            if cur_wait != 0 or costs[pozx][pozy] != 0:
                if H - cur_cost * 10 - 20 >= floors[pozx][pozy]:
                    cur_cost += 1
                else:
                    cur_cost += 10
            if costs[new_pozx][new_pozy] > cur_cost:
                costs[new_pozx][new_pozy] = cur_cost
                queue.append((new_pozx,new_pozy,costs[new_pozx][new_pozy]))
    
    ans = ans + "Case #" + str(nrt + 1) + ": " + str(costs[n - 1][m - 1]) + "\n"

g.write(ans)
