import sys

args = sys.argv

if len(args) == 2:
    readLoc = args[1]
    f = open(readLoc,'r')
    of = open('output.txt','w')
    breakFlag = False
    num = 0
    numCalculated = False
    i = -1
    while not breakFlag:
        l = f.readline()
        if not numCalculated:
            num = int(l.strip())
            numCalculated = True
            i = 0
        elif i < num:
            l = l.strip()
            ls = l.split(' ')
            X = int(ls[0])
            R = int(ls[1])
            C = int(ls[2])
            
            ans = True
            
            if X >= 7 :
                ans = False 
            elif X > R and X > C:
                ans = False 
            elif (R * C) % X != 0 :
                ans = False 
            elif (X + 1 ) // 2 > min (R, C):
                ans = False 
            elif X in ( 1 , 2 , 3 ):
                ans = True 
            elif X == 4 :
                ans = min(R, C) > 2 
            elif X == 5 :
                ans = not (min(R, C) == 3  and max(R, C) == 5)
            elif X == 6 :
                ans = min(R, C)> 3
            of.write('Case #%d:' % (i + 1 ) + (' GABRIEL\n'  if ans else  ' RICHARD\n') )
            print( 'Case #%d:' % (i + 1 ), 'GABRIEL'  if ans else  'RICHARD' )
            i = i + 1
        else:
            breakFlag = True
    of.flush()
    of.close()
    f.close()

sys.exit()
                
