"""B
   Google CodeJam 2013
"""

from datetime import datetime
from collections import namedtuple


def routine(X,Y):
    Pos = namedtuple('Pos', ['x','y'])
    p = [0,0]  # Pos(0,0)
    target = [X,Y]  #Pos(X,Y)
    path = []
    
    jump = 1
    while p != target:
        if (p[0] + jump == target[0]):
            p[0] += jump  #done
            path.append('E')
        elif (p[0] - jump == target[0]):
            p[0] -= jump  #done
            path.append('W')
        elif (p[1] + jump == target[1]):
            p[1] += jump  #done
            path.append('N')
        elif (p[1] - jump == target[1]):
            p[1] -= jump  #done
            path.append('S')
        else:
            canmovex = p[0] != target[0]
            canmovey = p[1] != target[1]
            movex = False
            if canmovex and canmovey:
                if jump % 2 == target[0] % 2:
                    movex = True
                elif jump % 2 == target[1] % 2:
                    movex = False
                
            if movex or not canmovey:
                if p[0] + jump < target[0]:
                    p[0] += jump
                    path.append('E')
                else:
                    p[0] -= jump
                    path.append('W')
            elif canmovey:
                if p[1] + jump < target[1]:
                    p[1] += jump
                    path.append('N')
                else:
                    p[1] -= jump
                    path.append('S')
        
        jump += 1
        print p, path, jump
    
    
    return "".join(path)

if __name__ == '__main__':
    filename = "B-small-attempt0"  #B-large
    f = open(filename + ".in")
    fo = open(filename + ".out", "w")

    print datetime.now()

    c = int(f.readline().strip())
    print c, "cases"
    for case in xrange(c):
        X, Y = [int(x) for x in f.readline().split()]
        
        print X,Y

        print >>fo, "Case #%d: %s" % (case+1, routine(X,Y))

    fo.close()
    f.close()
    print datetime.now()
