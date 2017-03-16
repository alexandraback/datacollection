inf = open("inf.txt", "r")
ouf = open("ouf.txt", "w")

for i in range(int(inf.readline())):
    c, d, v = map(int, inf.readline().split())
    domin = list(map(int, inf.readline().split()))
    
    count = 0
    
    cur_max = 0
    pos = 0
    for i1 in range(1, v + 1):
        if i1 == domin[pos]:
            cur_max += domin[pos]
            pos += 1
        elif cur_max < i1:
            count += 1
            cur_max += i1
            
    ouf.write("Case #" + str(i + 1) + ": " + str(count) + "\n")

inf.close()
ouf.close()