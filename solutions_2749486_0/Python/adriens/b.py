import sys

from collections import deque


class Case(object):
    def __init__(self, val=10000, path=[]):
        self.val = val
        self.path = path

def precalc():
    tab = {}

    to_study = deque()
    
    
    to_study.append((0,0))
    c=Case()
    c.val=0
    c.path = []
    tab[(0,0)] = c
    
    count = 0 
    
    while(len(to_study)>0):
         sys.stderr.write("len to_study: %i\n"%len(to_study))
         stu = to_study.popleft()
         key = (stu[0], stu[1])
         
         c = tab[key]
         
         count+=1
         
         if c.val>500:
             break
         
         for dir in list("NSEW"):
             if dir=="N":
                 d = (0,1)
             if dir=="S":
                 d = (0, -1)
             if dir == "E":
                 d = (1,0)
             if dir == "W":
                 d = (-1, 0)
                 
                 
             newcoords = (stu[0]+(c.val+1)*d[0], stu[1]+(c.val+1)*d[1])
             if abs( newcoords[0]) >201:
                 break
             if abs( newcoords[1]) >201:
                 break    
                 
             
#              print "newcoords:", newcoords
             newkey = newcoords
             newcase = tab.get(newkey, None )
             if newcase is None:
#                 print "creation"
                newcase = Case()
            
#              print c.val
#              print "newval:", newcase.val
             if c.val+1 < newcase.val:
#                 print "mieux"
                newcase.val = c.val+1
                newcase.path = c.path[:]
                newcase.path.append(dir)
                tab[newkey] =  newcase
                to_study.append((newcoords))
         
             

    return tab
    
    


if __name__=="__main__":
    T = int(sys.stdin.readline())
    tab = precalc()
    for t in xrange(T):
        l = sys.stdin.readline()
        x,y = [int(i) for i in l.split()]
        print "Case #%i:"%(t+1), "".join(tab[x,y].path)

