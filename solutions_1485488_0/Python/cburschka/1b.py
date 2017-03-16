def kayak(floors, ceilings, H, x, y):
    roving = True
    positions = [[-1]*x for i in range(y)]
    positions[0][0] = 0
    while roving:
        roving = False
        for i in range(y):
            for j in range(x):
                if positions[i][j] == 0:
                    for (a,b) in [(1,0), (-1,0), (0,1), (0,-1)]:
                        if can_move(floors, ceilings, H, (i,j), (i+a,j+b), (y,x)):
                            if positions[i+a][j+b] < 0:
                                positions[i+a][j+b] = 0
                                roving = True

    seconds = 0
    roving = True
    while positions[-1][-1] < 0 or roving:
        roving = False
        for i in range(y):
            for j in range(x):
                if 0 <= positions[i][j] <= seconds + 0.01:
                    for (a,b) in [(1,0), (-1,0), (0,1), (0,-1)]:
                        if can_move(floors, ceilings, H - seconds*10, (i,j), (i+a,j+b), (y,x)):
                            move = 10 if (floors[i][j] + 20 >= (H - seconds*10)) else 1
                            if positions[i+a][j+b] < 0 or positions[i+a][j+b] > seconds + move:
                                roving = True
                                positions[i+a][j+b] = seconds + move
        #print seconds, H-seconds*10
        #print "\n".join(map(lambda l:"\t".join(map(str, l)), positions))
        #print "--------------------"
        seconds += 0.1
    return positions[-1][-1]

def can_move(floors, ceilings, H, (i,j), (t,u), (y,x)):
    if not ((0 <= t < y) and (0 <= u < x)):
        return False
    if max(H, floors[i][j], floors[t][u]) + 49.999 > ceilings[t][u]:
        #print "Blub"
        return False
    if floors[t][u] + 50 > ceilings[i][j]:
        return False
    return True



n = int(raw_input())

for i in range(n):
    h,y,x = map(int, raw_input().split())
    ceilings, floors = [], []
    for row in range(y):
        ceilings.append(map(int, raw_input().split()))
    for row in range(y):
        floors.append(map(int, raw_input().split()))
    result = kayak(floors, ceilings, h, x, y)    
    print "Case #%d: %.1f" % (i+1, result)
