T = int ( input() )
i = 1
while T>0: 
    T -= 1
    R,C,W = map( int , input().split())
    if C == W:
        print( "Case #"+str(i)+": " + str( (R-1)* int(C/W) + W ) )
    else:
        if C % W == 0:
            print( "Case #"+str(i)+": " + str( (R-1)* int(C/W) + int(C/W)+(W-1) ) )
        else:
            print( "Case #"+str(i)+": " + str( (R-1)* int(C/W) + int(C/W)+(W) ) )
    i +=1
