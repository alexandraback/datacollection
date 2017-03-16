fin = open('D-large.in', 'r')
fout = open('out.txt', 'w')
t = int(fin.readline())
for casecount in range(1, t+1):
    num = int(fin.readline())
    naomi = [float(x) for x in fin.readline().split()]
    naomi.sort()
    ken = [float(x) for x in fin.readline().split()]
    ken.sort()
    head = 0
    y = 0
    for top in range(0, num):
        if naomi[top] > ken[head]:
            head = head + 1
            y = y + 1
    z = 0
    head = num - 1
    for top in range(num - 1, -1, -1):
        if naomi[top] > ken[head]:
            z = z + 1
        else:
            head = head - 1
    fout.write('Case #' + str(casecount) + ': ' + str(y) + ' ' + str(z) + '\n');
fin.close()
fout.close()
                
            
