for t in range (int (raw_input())):
    
    X, R, C = map (int, raw_input(). split())
    
    ans = True
    
    if X >= 7 :
        ans = False
    elif X > R and X > C:
        ans = False
    elif R * C % X is not 0 :
        ans = False
    elif (X + 1 ) // 2 > min (R, C):
        ans = False
    elif X in ( 1 , 2 , 3 ):
        ans = True
    elif X == 4 :
        ans = min (R, C)> 2
    elif X == 5 :
        ans = not (min (R, C) == 3  and max (R, C) == 5 )
    elif X == 6 :
        ans = min (R, C)> 3

    print 'Case #%d:' % (t + 1), 'GABRIEL'  if ans else  'RICHARD'