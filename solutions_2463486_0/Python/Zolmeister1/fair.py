import math

fin = map(lambda x: map(int, x.split(' ')), open('fair.in').read().strip().split('\n'))
fout = open('fair.out','w')
    
def pal(n):
    ss = str(n)
    return ss == ss[::-1]
        
pals = []

numm = int(math.ceil(math.sqrt(10**14+1)+1))
for i in xrange(1,numm):
    if pal(i) and pal(i**2):
        pals.append(i**2)
        
print pals

caseC = 1
for case in fin:
    cnt = 0
    for p in pals:
        if case[0]>p:
            continue
        if case[1]<p:
            break
        cnt+=1
    print 'Case #'+str(caseC)+': '+str(cnt)
    fout.write('Case #'+str(caseC)+': '+str(cnt)+'\n')
    caseC+=1
fout.close()