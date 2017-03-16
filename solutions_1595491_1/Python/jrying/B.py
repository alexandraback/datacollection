import sys

infile = open('B-large.in')
outfile = open('out.txt', 'wb')

infile.readline()
i = 0
for line in infile.readlines():
    listt = line.split(' ')
    S = int(listt[1])
    p = int(listt[2])
    ps = max(p*3-4, p)
    pns = max(p*3-2, p)
    result = 0
    for point in listt[3:]:
        pint = int(point)
        if pint >= pns:
            result = result +1
        elif pint >= ps and S > 0:
            S = S - 1
            result = result +1
    i = i + 1
    outfile.write('Case #'+str(i)+': '+str(result)+'\n')
    #print 'Case #'+str(i)+': '+str(result)

    
infile.close()
outfile.close()
