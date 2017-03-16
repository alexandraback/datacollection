inf = open("inf.txt", "r")
ouf = open("ouf.txt", "w")

for i in range(int(inf.readline())):
    c, d, v = map(int, inf.readline().split())
    domin = list(map(int, inf.readline().split()))
    
    count = 0
    
    cur_max = 0
    pos = 0
    i1 = 1
    while i1 <= v:
        if pos < len(domin) and domin[pos] <= i1:
            cur_max += domin[pos] * c
            pos += 1
        else:
            count += 1
            cur_max += i1 * c
        i1 = cur_max + 1
            
    ouf.write("Case #" + str(i + 1) + ": " + str(count) + "\n")

inf.close()
ouf.close()