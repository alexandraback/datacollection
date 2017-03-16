t = int(raw_input())

for i in xrange(t):
    name, n = raw_input().split()
    n = int(n)
    l = len(name)
    tmp = 0
    res = 0
    start = 0
    cstart = 0
    for j, ch in enumerate(name):
        if ch not in ('a', 'e', 'i', 'o', 'u'):
            tmp += 1
        else:
            tmp = 0
            cstart = j+1

        if tmp >= n:
             
            if cstart - start > 0:
                #print  " test ", cstart, start, j , l 
                res += ( (cstart - start + 1 )  * (l - j  )) 
            else:
                res += (l - j) 
            #print name[start:], res, cstart
            
            cstart += 1
            start = cstart
            
    print "Case #%s: %s"% (i+1, res)

    

