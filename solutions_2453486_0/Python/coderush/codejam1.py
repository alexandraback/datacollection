import sys
import math

sys.stdin=open("A.in")
t = int(sys.stdin.readline())
for i in range(t):
    game=[]
    for j in range(4):
       game.append(sys.stdin.readline())
    sys.stdin.readline()
    #print (game)
    xwins=0
    owins=0
    flag=0
    
    for k in (['XXXX\n','XXXT\n','XXTX\n','XTXX\n','TXXX\n']):
        xwins=xwins+(game.count(k))
    for k in (['OOOO\n','OOOT\n','OOTO\n','OTOO\n','TOOO\n']):
        owins=owins+(game.count(k))
    if ((xwins==0) or (owins==0)):
        game1=[]
        for l in [0,1,2,3]:
            game1.append(game[0][l]+game[1][l]+game[2][l]+game[3][l])
        for k in (['XXXX','XXXT','XXTX','XTXX','TXXX']):
            xwins=xwins+(game1.count(k))
        for k in (['OOOO','OOOT','OOTO','OTOO','TOOO']):
            owins=owins+(game1.count(k))
        if ((xwins==0) or (owins==0)):
            diag1=game[0][0]+game[1][1]+game[2][2]+game[3][3]
            diag2=game[0][3]+game[1][2]+game[2][1]+game[3][0]
            for k in (['XXXX','XXXT','XXTX','XTXX','TXXX']):
                xwins=xwins+(diag1.count(k))
                xwins=xwins+(diag2.count(k))
            for k in (['OOOO','OOOT','OOTO','OTOO','TOOO']):
                owins=owins+(diag1.count(k))
                owins=owins+(diag2.count(k))
            if ((xwins==0) or (owins==0)):
                
                for l in game:
                    flag=flag+l.count('.')
    myfile=open("output.out",mode='a')
    sys.stdout=myfile
    if xwins>0:
         print ("Case #"+str(i+1)+": X won",end='\n',file=sys.stdout)
    elif owins>0:
         print ("Case #"+str(i+1)+": O won",end='\n',file=sys.stdout)
    elif flag>0:
         print ("Case #"+str(i+1)+": Game has not completed",end='\n',file=sys.stdout)
    else:
         print ("Case #"+str(i+1)+": Draw",end='\n',file=sys.stdout)
    myfile.close()
