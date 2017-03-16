import sys

vowels = set(['a', 'e', 'i', 'o', 'u'])

T = int(sys.stdin.readline())
for case in xrange(1, T+1):
    [L, n] = sys.stdin.readline().split()
    n = int(n)
    #print "testcase:", L, n
    cnt = 0
    for start in xrange(len(L)):
        for end in xrange(start, len(L)):
            if (end - start + 1) >= n:
                #print (start, end), L[start:end+1], "length:", (end - start + 1)
                for i in xrange(start, end-n+2):
                    #print "starting from ", i, L[i]
                    if L[i] not in vowels:
                        good = True
                        for j in xrange(i+1, i+n):
                            #print L[j]
                            if L[j] in vowels:
                                good = False
                                break
                        if good:
                            #print "good!", i
                            cnt += 1
                            break
                            
                        
                
    
    print "Case #"+str(case)+": "+str(cnt)
