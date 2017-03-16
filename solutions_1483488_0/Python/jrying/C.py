import sys

infile = open('C-small-attempt0 (1).in')
outfile = open('out.txt', 'wb')

infile.readline()
count = 0
for line in infile.readlines():
    listt = line.split(' ')
    A = int(listt[0])
    B = int(listt[1])
    print A,B
    record = [1]*2000001
    result = 0
    for i in range(A, B+1):
        if(not record[i]):
            continue;
        alti = 1
        tempi = i
        record[tempi] = 0
        l = len(str(i))
        p = pow(10, l-1)
        for j in range(0, l):
            tempi = tempi%10*p+tempi/10
            if(tempi > 2000000):
                continue
            if(record[tempi] and tempi >= A and tempi <=B):
                alti = alti + 1
            record[tempi] = 0
        result += alti*(alti-1)/2
    count += 1
    outfile.write('Case #'+str(count)+': '+str(result)+'\n')
    #print 'Case #'+str(count)+': '+str(result)

infile.close()
outfile.close()
