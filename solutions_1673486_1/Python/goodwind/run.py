def solve(b,p):
    res = 2+b
    a = len(p)
    pp = []
    tmp=1
    for x in p: 
        tmp*=x
        pp.append(tmp)
    res = min(res,1+b-a+(1-pp[-1])*(b+1))
    for c in range(a-1):
        res = min(res,2*(a-1-c)+b-a+1+(1-pp[c])*(b+1))
    return res

fi = open("input.txt")
nTest = int(fi.readline())
for testID in range(nTest):
    a,b = map(int,fi.readline().split())
    p = map(float,fi.readline().split())
    #print a,b,p
    print "Case #"+str(testID+1)+":",solve(b,p)
    
fi.close()