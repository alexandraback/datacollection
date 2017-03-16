f = open("data.txt", 'r')
g = open("data1.txt", 'w')

line = f.readline()
n = int(line)
for i in range(1, n+1):
    line = f.readline()
    m = int(line)
    levels = []
    for j in range(m):
        line = f.readline()
        (a, b) = (int(x) for x in line.split())
        levels.append([b, a, 0])
    levels.sort()
    stars = 0
    result = 0
    while levels != []:
        if levels[0][0] <= stars:
            result += 1
            if levels[0][2] == 1:
                stars += 1
            else:
                stars += 2
            del levels[0]
            print(levels)
            continue
        else:
            for r in range(len(levels)-1, -1, -1):
                if levels[r][2] != 1 and levels[r][1] <= stars:
                    levels[r][2] = 1
                    result += 1
                    stars += 1
                    print(levels)
                    break
            else:
                result = -1
                break
    if result == -1:
        sresult = "Too Bad"
    else:
        sresult = str(result)
    string = "Case #" + str(i) + ": " + sresult + '\n'
    g.write(string)
    
f.close()
g.close()
