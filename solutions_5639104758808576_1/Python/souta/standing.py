fin = open('A-large.in','r')
fout = open('output.txt','w')
t = int(fin.readline())
for count in range(1, t + 1):
    line = fin.readline()
    smax = int(line.split()[0])
    audience = line.split()[1]
    total = int(audience[0])
    maxgap = 0
    for i in range(1, smax + 1):
        if maxgap < i - total:
            maxgap = i - total
        total += int(audience[i])
    fout.write('Case #'+str(count)+': '+ str(maxgap) +'\n')
fin.close()
fout.close()
