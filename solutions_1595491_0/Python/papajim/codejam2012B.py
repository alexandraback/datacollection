f = open(r'B-small-attempt0.in', 'r')
g = open(r'outputBsmall.out', 'w')
t = int(f.readline())
for i in range(1, t+1):
    g.write("Case #"+str(i)+": ")
    case = f.readline().replace('\n', '').split(' ')
    n = int(case[0])
    s = int(case[1])
    p = int(case[2])
    count = 0
    for k in range(n):
        if int(case[3+k])%3 > 0:
            if int(case[3+k])%3 == 1 and int(int(case[3+k])/3) + int(case[3+k])%3 < 11 and int(int(case[3+k])/3) + int(case[3+k])%3 >= p:
                count += 1
            elif int(case[3+k])%3 == 2:
                if int(int(case[3+k])/3) + 1 < 11 and int(int(case[3+k])/3) + 1 >= p:
                    count += 1
                elif int(int(case[3+k])/3) + 2 < 11 and int(int(case[3+k])/3) + 2 >= p and s > 0:
                    count += 1
                    s -= 1
        else:
            if int(int(case[3+k])/3) >= p:
                count += 1
            elif int(case[3+k]) > 0 and int(int(case[3+k])/3) + 1 < 11 and int(int(case[3+k])/3) + 1 >= p and s > 0:
                count += 1
                s -= 1
    g.write(str(count)+"\n")
f.close()
g.close()
