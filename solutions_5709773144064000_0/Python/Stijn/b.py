f = open('D:/Projects/Python Environment/Projecten/Code Jam/2014/b/in.in')
T = int(f.readline().strip())
lines = []
for i in range(T): lines.append(f.readline().strip().split(' '))

from decimal import *

fo = open('D:/Projects/Python Environment/Projecten/Code Jam/2014/b/out.out','wb'); 
import math
 
for i in range(T):
    C = Decimal(lines[i][0]);
    F = Decimal(lines[i][1]);
    X = Decimal(lines[i][2]);
    
    mintime = X/2;
    buildspeed = []
    buildspeed.append(0);
    totaltime = []
    totaltime.append(X/2);
    overalltotaltime = X/2;
    for j in range(1,int(math.ceil(X/C))):
            
       buildspeed.append(buildspeed[j-1]+C/(2+F*(j-1)));
       totaltime.append(buildspeed[j]+X/(2+F*j));
       if(totaltime[j]<overalltotaltime):
           overalltotaltime =totaltime[j];
       else:
           break;
        
    fo.write("Case #%d: %s\n" % (i+1,format(overalltotaltime, '.7f')))
    #fo.write("C %d\tF %d\tX %d\t%d\t%s\n" % (C,F,X,j,format(overalltotaltime, '.7f')))

fo.close()