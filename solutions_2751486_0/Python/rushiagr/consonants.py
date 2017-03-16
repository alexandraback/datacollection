
times = input()
for time in range(times):
    a = [i for i in raw_input().split()]
    s = a[0]
    n = int(a[1])
    l = len(s)
    
    finalans = 0
    vowels = ['a', 'e', 'i', 'o', 'u']
    
    for i in range(l):
        for j in range(l-1, i-1, -1):  # point of optimization
#            print 'i,j:', i, j
            if(j+1 < n):
                continue
            
            count = 0
            gotans = False
            for k in range(i,j+1):
                if s[k] not in vowels:
                    count+=1
                    if count == n:
#                        print 'i, j and k:', i, j, k
                        gotans = True
                        finalans += j-k+1
                        break
                else:
                    count=0
            if gotans == True:
                break
                        
                        
    print 'Case #%d: %d' % (time+1, finalans)
    
