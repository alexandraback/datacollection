from Queue import Queue
size = 1000
offSet = 500
T = [[False for x in range(size)] for y in range(size)]
T[offSet][offSet] = [0,'']
Q = Queue()
Q.put([offSet,offSet])
while not Q.empty():
    x,y = Q.get()
    count, path = T[x][y]
    if x + count + 1 < size and not T[x + count + 1][y]:
        T[x + count + 1][y] = [count + 1, path + "E"]
        Q.put([x + count + 1, y])
    if x - count - 1 >= 0 and not T[x - count - 1][y]:
        T[x - count - 1][y] = [count +1, path + "W"]
        Q.put([x - count - 1, y])
    if y + count + 1 < size and not T[x][y + count + 1]:
        T[x][y + count + 1] = [count + 1, path + "N"]
        Q.put([x, y + count + 1])
    if y - count - 1 >= 0 and not T[x][y - count - 1]:
        T[x][y - count - 1] = [count + 1, path + "S"]
        Q.put([x, y - count - 1])
for t in range(1, int(raw_input()) + 1):
    print "Case #"+str(t)+":",
    x,y = [int(k) + offSet for k in raw_input().split()]
    print T[x][y][1]
    
