f = file("ConsonantsSmall.txt").readlines()
fout = open("ConsonantsSmalOutput.txt",'w')
for i in f:
    f[f.index(i)] = i.strip()

def test(name,n):
    s = name.lower()
    desired = 'c'*n
##    print desired
    d = ''
    for i in s:
        if i in ['a', 'e','i', 'o', 'u']:
            d+='v'
        else:
            d+='c'
##    strlist = []
##    print d
    count = 0
    for a in range(0,len(d)+1):
        for b in range(a+1,len(d)+1):
##            strlist.append(d[a:b])
            if desired in d[a:b]:
                count+=1
##    print strlist
    return count

    

tc = int(f[0])
count = 0
for i in range(tc):
    count+=1
    name = f[count].split()[0]
    n = int(f[count].split()[1])
    dec = test(name,n)
    fout.write('Case #' + str(i+1) + ': ' + str(dec) + '\n')
    print 'Case #' + str(i+1) + ': ' + str(dec) + '\n'
