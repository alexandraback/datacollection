fn = 'B-small-attempt2'
fi = open('%s.in' % fn,'r')
fo = open('%s.out' % fn,'w')
t = int(fi.readline())

for i in range(t):
    n = int(fi.readline())
    # get data
    p1 = []
    p2 = []
    p1visited = []
    p2visited = []
    for j in range(n):
        [a, b] = map(lambda x: int(x), fi.readline().split(' '))
        p1.append(a)
        p2.append(b)
        p1visited.append(0)
        p2visited.append(0)
        
    act = True
    times = 0
    stars = 0
    while act:
        act = False
        for k in range(n):
            if p2visited[k]==0 and stars >= p2[k]:
                if p1visited[k]==1:
                    stars = stars + 1
                else:
                    stars = stars + 2
                times = times + 1
                p2visited[k] = 1
                p1visited[k] = 1
                act = True
                #print "V2 %s + 2 = %s" % ((k+1),stars)
                
        if sum(p2visited)==n:
            # over!
            break
        
        if act:
            continue

        for k in range(n):
            if p1visited[k]==0 and stars >= p1[k]:
                stars = stars + 1
                times = times + 1
                p1visited[k] = 1
                act = True
                #print "V1 %s + 1 = %s" % ((k+1),stars)
                break # once can find one, just pass

    if sum(p2visited)==n:
        print "Case #%s: %s" % ((i+1),times)
        fo.write("Case #%s: %s\n" % ((i+1),times))
    else:
        print "Case #%s: Too Bad" % ((i+1))
        fo.write("Case #%s: Too Bad\n" % ((i+1)))
        

fi.close()    
fo.close()
