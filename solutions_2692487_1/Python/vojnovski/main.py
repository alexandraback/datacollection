import os

def presmetaj(start, motes, dolz):
    # if starting mote is 1 there is no way to finish apart from deleting all
    if start < 2:
        return dolz
    motes.sort()
    summa = start
    operations = 0
    i = 0
    while i < len(motes):
        if summa > max(motes[i:]):
            return  min(dolz,operations)
        if summa > motes[i]:
            summa = summa + motes[i]
        else:
            tempop = 0
            while summa <= motes[i]:
                summa = summa + summa -1
                tempop = tempop + 1
            if tempop >= len(motes[i:]):
                return min(dolz, operations +len(motes[i:]) )
            else:
                operations = operations + tempop
                i = i -1
        i = i + 1
    return min(dolz,operations)
    
def presmetajs(s, s2):
    ns = [int(x) for x in s.split()]
    l1 = ns[0]
    l2 = ns[1]
    ns2 = [int(x) for x in s2.split()]
    return presmetaj(l1,ns2,l2)


problem = './A'
small = '-small'
large = '-large'
dev = '-dev'
if os.path.exists(problem + large+'.in'):
    fajl = problem + large
elif os.path.exists(problem + small+'.in'):
    fajl = problem + small
elif os.path.exists(problem + dev+'.in'):
    fajl = problem + dev
f = open(fajl+'.in', 'rU')
f2 = open(fajl+'.out', 'w')
r = ''
for i in range(int(f.readline())):
    r+='Case #' + str(i+1) + ': ' + str(presmetajs(f.readline(), f.readline())) + '\n'
f2.write(r)
f.close()
f2.close()