f = open(r'C-large.in', 'r')
g = open(r'C-large.out', 'w')
t = int(f.readline())
for i in range(1, t+1):
    g.write("Case #"+str(i)+": ")
    case = f.readline().replace('\n', '').split(' ')
    A = int(case[0])
    B = int(case[1])
    count = 0
    if B < 10:
        g.write('0\n')
    else:
        for k in range(A, B+1):
            num = str(k)
            l = []
            for j in range(1, len(num)):
                temp1 = num[-j:]
                temp2 = num[:-j]
                new = temp1+temp2
                if int(num) < int(new) and int(new) <= B and new not in l:
                    l.append(new)
            count += len(l)
        g.write(str(count)+"\n")
f.close()
g.close()
