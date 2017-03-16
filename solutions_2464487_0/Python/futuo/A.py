
memoise = {}

T = input();

for testCase in range(1,T+1):

    inpt = raw_input()
    r = float( inpt.split(" ")[0] )
    t = float( inpt.split(" ")[1] )
    r += 1

    total = 0

    while( True ):

        needed = r * r - ( (r-1) * (r-1) )
        
        if( needed > t ):
            break
        
        total += 1
        
        r += 2;
        t -= needed

    print "Case #"+str(testCase)+":", str(total)



