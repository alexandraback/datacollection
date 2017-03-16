def makePrintable(L):
    s = ""
    for x in L:
        s += str(x) + " "
    return s
    
    

f = open('a.in', 'r')
g = open('a.out', 'w')

t = int(f.readline())

for i in range(1,t+1):
    k,c,s = f.readline().split(' ')
    l = [x for x in range(1,int(s)+1)]
    pr = "Case #"+str(i)+ ": " + makePrintable(l)
    print pr
    g.write(pr + '\n')


f.close()
g.close()
