from sys import stdin

num_cases = int(stdin.readline())
for case_index in xrange(1, num_cases+1):
    n = int(stdin.readline().strip())
    lvls = []
    for i in xrange(n):
        lvls.append(map(int,stdin.readline().strip().split(' ')))

##    print n, lvls
  
    stars = 0
    movs = 0
    ans = ''
    
    while(len(lvls) > 0 and stars <= 2*n):

        max2 = -1
        maxi = -1
        found2 = False
        
        for i in xrange(len(lvls)):
##            print movs, stars, lvls[i][1], lvls[i][0], max2
            if stars >= lvls[i][1]:
                if len(lvls[i]) < 3:
                    stars += 2
                else:
                    stars += 1
                movs += 1

                found2 = True
##                print '** (%s) %s (%s %s)'%(stars, lvls[i], max2, movs)
                del lvls[i]                
                break
            elif stars >= lvls[i][0] and max2 < lvls[i][1] and len(lvls[i]) < 3:
##                print '- (%s) %s (%s %s)'%(stars, lvls[i], max2, movs)
                maxi = i
                max2 = lvls[i][1]

        if found2:
            continue
        
        if maxi <> -1:
            if len(lvls[maxi]) < 3:
                lvls[maxi].append(1)
                stars += 1
                movs += 1
##            print '* (%s) %s %s'%(stars,lvls[maxi], len(lvls[maxi]))            
            
        else:
            ans = 'Too Bad'
            break
        

    if ans == '':
        ans = str(movs) 
    
    print "Case #" + str(case_index) + ": " + ans
