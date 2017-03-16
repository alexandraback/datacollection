inp=raw_input
t=int(inp())
for i in range(t):
    print "Case #%d:" % (i+1),
    a,n=map(int, inp().split())
    ms=map(int, inp().split())
    ms.sort()
    if a==1:
        print n
    else:
        toDrop=0
        toAdd=0
        startDropping=False
        size=a
        drops=[]
        adds=[0]
        for j in ms:
            if size<=j:
                startDropping=True
                drops.append(toDrop)
                toDrop+=1
                while size<=j:
                    size+=size-1
                    toAdd+=1
                adds.append(toAdd)
            else:
                if startDropping:
                    toDrop+=1
            size+=j
        drops.append(toDrop)
        drops=map(lambda x: toDrop-x, drops)
        vals=map(lambda (x,y): x+y, zip(adds, drops))

        #print adds,drops,vals
        print min(vals+[toAdd])


