import sys

vowels = set(['a', 'e', 'i', 'o', 'u'])

def brute(L, n):
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
    return cnt    

T = int(sys.stdin.readline())
for case in xrange(1, T+1):
    [L, n] = sys.stdin.readline().split()
    n = int(n)
    #print "testcase:", L, n
    #cnt = brute(L, n)
    
    accum = [0]*len(L)
    i = 0
    while i < len(accum):
        if L[i] not in vowels:
            acc = 0
            while i < len(L) and L[i] not in vowels:
                acc += 1
                accum[i] = acc
                i+=1
        else:
            i += 1
    #print accum
    
    next_places = [-1]*len(L)
    next_pl = -1
    i = len(L) - 1
    while i >= 0:
        if accum[i] != 0:
            last = i
            while i >= 0 and accum[i] != 0:
                if last-i+1 >= n:
                    next_places[i] = i+n-1
                    next_pl = i+n-1
                else:
                    next_places[i] = next_pl
                i -= 1
        else:
            next_places[i] = next_pl
            i -= 1
            
    #print next_places
    
    cnt = 0
    for i in next_places:
        if i != -1:
            cnt += len(L) - i
    
    print "Case #"+str(case)+": "+str(cnt)
