def ok(k):
    #print "Trying ",k
    visited = [0]*n
    b = []
    for i in range(n):
        b.append((a[i][0],i,1))
        b.append((a[i][1],i,2))
    b.sort()
    cur = 0
    for x,i,j in b:
        #print x,i,j,cur
        if cur<x: return False
        if j==1:
            if k==0: continue
            k-=1
            cur+=1
            visited[i] = 1
        else:
            if visited[i]:
                cur+=1
            else: cur+=2
            visited[i] = 2
    #for i in range(n):
    #    if visited[i]!=2: return False
    return True
    
    

fi = open("input.txt")
nTest = int(fi.readline())
for testID in range(nTest):
    n = int(fi.readline())
    a = []
    for i in range(n):
        a.append(map(int,fi.readline().split()))
    l,r = 0,n
    if not ok(r):
        print "Case #"+str(testID+1)+":","Too Bad"
        continue
    while l<r:
        mid = (l+r)/2
        if ok(mid): r = mid
        else: l = mid+1
    print "Case #"+str(testID+1)+":",l+n
    
fi.close()